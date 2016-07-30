/*****************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 *****************************************************************************/

/*****************************************************************************
 * $Id: idlQueue.h 3773 2016-07-28 09:05:43Z randyma $
 *****************************************************************************/

#if !defined(_O_IDL_QUEUE_H_)
#define _O_IDL_QUEUE_H_ 1

#include <dkpSpinLock.h>
#include <idlMemPool.h>

typedef struct IDL_Queue IDL_Queue;

typedef struct IDL_QueueNode   IDL_QueueNode;
typedef struct IDL_QueueSmrRec IDL_QueueSmrRec;

typedef struct IDL_QueueOp
{
    SKP_RC (*mEnqueue)(IDL_Queue *aQueue, void *aObj);
    SKP_RC (*mDequeue)(IDL_Queue *aQueue, void **aObj);
} IDL_QueueOp;

typedef struct IDL_QueueLockFree
{
    aclQueueSmrRec *mSmrRec;
} IDL_QueueLockFree;

typedef struct IDL_QueueSpinLock
{
    SKP_SpinLock mHeadLock;
    SKP_SpinLock mTailLock;
} IDL_QueueSpinLock;

struct IDL_Queue
{
    union
    {
        IDL_QueueLockFree  mLockFree;
        IDL_QueueSpinLock  mSpinLock;
    } mSpec;

	SKP_SInt              mParallelFactor;
    IDL_QueueOp           *mOp;
    IDL_QueueNode         *mHead;
    IDL_QueueNode         *mTail;

    volatile acp_sint32_t          mNodeCount;
};

SKP_RC idlQueueCreate(IDL_Queue *aQueue, SKP_SInt aParallelFactor);

void idlQueueDestroy(IDL_Queue *aQueue);

SKP_Bool idlQueueIsEmpty(IDL_Queue *aQueue);

SKP_INLINE SKP_RC idlQueueEnqueue(IDL_Queue *aQueue, void *aObj)
{
    return aQueue->mOp->mEnqueue(aQueue, aObj);
}

SKP_INLINE SKP_RC aclQueueDequeue(IDL_Queue *aQueue, void **aObj)
{
    return aQueue->mOp->mDequeue(aQueue, aObj);
}

SKP_INLINE SKP_SInt idlQueueGetCount(IDL_Queue *aQueue)
{
    dkp_sint32 sCount = aQueue->mNodeCount;
    return (sCount < 0)? 0 : sCount;
}

#endif /* _O_IDL_QUEUE_H_ */
