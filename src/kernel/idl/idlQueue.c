/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 *
 * Lock-Free FIFO Queue implementation based on:
 *
 * Maged M. Michael
 * Hazard Pointers: Safe Memory Reclamation for Lock-Free Objects.
 * IEEE TPDS, 2004
 *
 * Maged M. Michael
 * Safe Memory Reclamation for Dynamic Lock-Free Objects
 * Using Atomic Read and Writes.
 * ACM PODC, 2002
 *
 * Maged M. Michael, Michael L. Scott
 * Simple, Fast, and Practical Non-Blocking and Blocking
 * Concurrent Queue Algorithms.
 * ACM PODC, 1996
 ******************************************************************************/

#include <idpThr.h>
#include <idlQueue.h>

#define IDL_QUEUE_LOCKFREE_ENABLED

/*
 * SMR (Safe-Memory Reclamation) Constants
 *
 * P: number of participating threads       = aQueue->mParallelFactor
 * K: number of harzard pointers per thread = idl_QUEUE_SMR_HP_COUNT
 * R: batch size                            = idl_QUEUE_SMR_BATCH_SIZE
 */
#define IDL_QUEUE_SMR_HP_COUNT    2
#define IDL_QUEUE_SMR_BATCH_SIZE  128

#define IDL_QUEUE_CAS(aPtr, aWith, aCmp)                                \
    (void *)idpAtomicCas((aPtr), (acp_ulong_t)(aWith), (acp_ulong_t)(aCmp))


struct IDL_QueueNode
{
    void          *mObj;
    IDL_QueueNode *mNext;
};

struct IDL_QueueSmrRec
{
    IDP_SpinLock   mLock;
    IDS_SInt       mRetiredCount;
    IDL_QueueNode *mRetiredNodes[IDL_QUEUE_SMR_BATCH_SIZE];
    IDL_QueueNode *mHazardNodes[IDL_QUEUE_SMR_HP_COUNT];
};

/* SMR Functions */
IDS_INLINE void idlQueueNullifyNode( IDL_QueueNode  *aNodeToNullify,
                                     IDL_QueueNode **aNodeArray,
                                     IDS_SInt        aNodeCount )
{
}

IDS_INLINE void idlQueueFreeSafeNodes( IDL_Queue *aQueue,
                                       IDL_QueueSmrRec *aSmrRec)
{
}

IDS_INLINE void idlQueueRetireNode( IDL_Queue    *aQueue,
                                    IDL_QueueSmrRec *aSmrRec,
                                    IDL_QueueNode   *aNode)
{
}

/* SMR Record List */
IDS_INLINE IDL_QueueSmrRec *idlQueueSmrRecTryLock(IDL_Queue  *aQueue, IDS_UInt  aIndex)
{
    return NULL;
}

IDS_INLINE IDL_QueueSmrRec *idlQueueSmrRecLock(IDL_Queue *aQueue)
{
    return NULL;
}

IDS_INLINE void idlQueueSmrRecUnlock(IDL_QueueSmrRec *aSmrRec)
{
}

static IDS_RC idlQueueEnqueueLockFree(IDL_Queue *aQueue, void *aObj)
{
    return IDS_RC_SUCCESS;
}

static IDS_RC idlQueueDequeueLockFree(IDL_Queue *aQueue, void **aObj)
{
    return IDS_RC_SUCCESS;
}

static IDS_RC idlQueueEnqueueSpinLock(IDL_Queue *aQueue, void *aObj)
{
    return IDS_RC_SUCCESS;
}

static IDS_RC idlQueueDequeueSpinLock(IDL_Queue *aQueue, void **aObj)
{
    return IDS_RC_SUCCESS;
}

static IDS_RC idlQueueEnqueueNoLock(IDL_Queue *aQueue, void *aObj)
{
    return IDS_RC_SUCCESS;
}

static IDS_RC idlQueueDequeueNoLock(IDL_Queue *aQueue, void **aObj)
{
    return IDS_RC_SUCCESS;
}

static IDL_QueueOp gidlQueueOpLockFree =
{
    idlQueueEnqueueLockFree,
    idlQueueDequeueLockFree,
};

static IDL_QueueOp gidlQueueOpSpinLock =
{
    idlQueueEnqueueSpinLock,
    idlQueueDequeueSpinLock,
};

static IDL_QueueOp gidlQueueOpNoLock =
{
    idlQueueEnqueueNoLock,
    idlQueueDequeueNoLock,
};


IDS_INLINE IDS_RC idlQueueInitLockFree(IDL_Queue *aQueue)
{
    return IDS_RC_SUCCESS;
}

IDS_INLINE IDS_RC idlQueueInitSpinLock(IDL_Queue *aQueue)
{
    return IDS_RC_SUCCESS;
}

IDS_INLINE IDS_RC idlQueueInitNoLock(IDL_Queue *aQueue)
{
    return IDS_RC_SUCCESS;
}

IDS_INLINE void idlQueueFinalLockFree(IDL_Queue *aQueue)
{
}

IDS_INLINE void idlQueueFinalSpinLock(IDL_Queue *aQueue)
{
}

IDS_INLINE void idlQueueFinalNoLock(IDL_Queue *aQueue)
{
}

/* creates a FIFO queue */
IDS_RC idlQueueCreate( IDL_Queue *aQueue, IDS_SInt aParallelFactor )
{
    return IDS_RC_SUCCESS;
}

/**
 * destroys a queue
 */
void idlQueueDestroy(IDL_Queue *aQueue)
{
}

/**
 * checks whether the queue is empty or not
 */
IDS_Bool idlQueueIsEmpty(IDL_Queue *aQueue)
{
    return IDS_RC_SUCCESS;
}
