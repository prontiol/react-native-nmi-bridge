/**
 @brief The possible reasons a swipe reader may become unready to receive a swipe.
 */
enum SwipeReasonUnreadyForSwipe
{
    /**
     @brief The reader has been detached or is powered down.
     */
    SwipeReasonUnreadyForSwipeDisconnected,
    
    /**
     @brief The reader did not receive a swipe before the request timed out.
     @details This only applies to the Shuttle reader.
     */
    SwipeReasonUnreadyForSwipeTimedOut,
    
    /**
     @brief A swipe was canceled by a call to cancelSwipeRequest.
     @details This only applies to the Shuttle reader.
     */
    SwipeReasonUnreadyForSwipeCanceled,
    
    /**
     @brief The reader is only momentarily unable to accept swipes.  A new request will be issued immediately without any intervention.
     @details This occurs when Shuttle readers are in alwaysAcceptSwipe mode and the underlying device times out or receives a swipe.  If this reason is received, it is not possible to determine the reason the swipe is momentarily unready.  This only applies to the Shuttle reader.
     */
    SwipeReasonUnreadyForSwipeRefreshing,
    
    /**
     @brief A swipe was received.
     @details Card data may or may not have been received.  Check the didSwipeCard message for details.
     */
    SwipeReasonUnreadyForSwipeSwipeDone
};

/**
 @brief The possible reasons a swipe reader may become unready to receive a swipe.
 */
typedef enum SwipeReasonUnreadyForSwipe SwipeReasonUnreadyForSwipe;
