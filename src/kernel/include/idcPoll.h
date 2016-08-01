/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDC_POLL_H_)
#define _O_IDC_POLL_H_ 1

#include <idcSock.h>

#define IDC_POLL_IN  EPOLLIN
#define IDC_POLL_OUT EPOLLOUT

/* object to describe returned event */
typedef struct IDC_PollObj
{
    IDS_SInt  mReqEvent; /**< requested events            */
    IDS_SInt  mRtnEvent; /**< returned events             */
    IDC_Sock *mSock;     /**< the socket                  */
    void     *mUserData; /**< associated opaque user data */
} IDC_PollObj;

/* poll set */
typedef struct IDC_PollSet
{
    IDS_SInt        mMaxCount;    /* number of object can be registered   */
    IDS_SInt        mCurCount;    /* number of registered object          */
    IDC_PollObk     *mObjs;       /* registered object array              */

    struct epoll_event *mEvents;  /* returned event array from epoll      */
    IDS_SInt        mHandle;      /* epoll descriptor                     */
    IDS_UInt        mCurrEvent;   /* cancelled descriptor for resume      */
    IDS_UInt        mEventsNum;   /* number of polled descriptors         */
} IDC_PollSet;

/* event handling callback function for idcPollDispatch() */
typedef IDS_SInt IDC_PollCallback( IDC_PollSet       *aPollSet,
                                   const IDC_PollObj *aPollObj, 
                                   void              *aContext );

IDS_RC idcPollCreate(IDC_PollSet *aPollSet, IDS_SInt aMaxCount);

IDS_RC idcPollDestroy(IDC_PollSet *aPollSet);

IDS_RC idcPollAddSock( IDC_PollSet *aPollSet,
                       IDC_Sock    *aSock,
                       IDS_SInt     aEvent,
                       void        *aUserData );

IDS_RC idcPollRemoveSock(IDC_PollSet *aPollSet, IDC_Sock *aSock);

IDS_RC idcPollDispatch( IDC_PollSet      *aPollSet,
                        IDP_Time          aTimeout,
                        IDC_PollCallback *aCallback, 
                        void             *aContext );

IDS_RC idcPollDispatchResume( IDC_PollSet      *aPollSet,
                              IDC_PollCallback *aCallback,
                              void             *aContext );

#endif /* _O_IDC_POLL_H_ */

