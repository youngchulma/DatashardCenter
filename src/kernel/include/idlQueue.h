/*****************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 *****************************************************************************/

/*****************************************************************************
 * $Id$
 *****************************************************************************/

#if !defined(_O_IDL_QUEUE_H_)
#define _O_IDL_QUEUE_H_ 1

#include <idpSpinLock.h>
#include <idlMemPool.h>

typedef struct IDL_Queue IDL_Queue;

typedef struct IDL_QueueNode   IDL_QueueNode;
typedef struct IDL_QueueSmrRec IDL_QueueSmrRec;

typedef struct IDL_QueueOp
{
    IDS_RC (*mEnqueue)(IDL_Queue *aQueue, void *aObj);
    IDS_RC (*mDequeue)(IDL_Queue *aQueue, void **aObj);
} IDL_QueueOp;

typedef struct IDL_QueueLockFree
{
    IDL_QueueSmrRec *mSmrRec;
} IDL_QueueLockFree;

typedef struct IDL_QueueSpinLock
{
    IDP_SpinLock mHeadLock;
    IDP_SpinLock mTailLock;
} IDL_QueueSpinLock;

struct IDL_Queue
{
    union
    {
        IDL_QueueLockFree  mLockFree;
        IDL_QueueSpinLock  mSpinLock;
    } mSpec;

	IDS_SInt              mParallelFactor;
    IDL_QueueOp           *mOp;
    IDL_QueueNode         *mHead;
    IDL_QueueNode         *mTail;

    volatile IDS_SInt     mNodeCount;
};

IDS_RC idlQueueCreate(IDL_Queue *aQueue, IDS_SInt aParallelFactor);

void idlQueueDestroy(IDL_Queue *aQueue);

IDS_Bool idlQueueIsEmpty(IDL_Queue *aQueue);

IDS_INLINE IDS_RC idlQueueEnqueue(IDL_Queue *aQueue, void *aObj)
{
    return aQueue->mOp->mEnqueue(aQueue, aObj);
}

IDS_INLINE IDS_RC aclQueueDequeue(IDL_Queue *aQueue, void **aObj)
{
    return aQueue->mOp->mDequeue(aQueue, aObj);
}

IDS_INLINE IDS_SInt idlQueueGetCount(IDL_Queue *aQueue)
{
    IDS_SInt sCount = aQueue->mNodeCount;
    return (sCount < 0)? 0 : sCount;
}

#endif /* _O_IDL_QUEUE_H_ */
