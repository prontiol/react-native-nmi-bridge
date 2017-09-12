/**
 @brief The possible results of an attempt to activate a swipe reader.
 */
enum SwipeActivationResult {
    /**
     @brief Successful activation.
     */
    SwipeActivationResultSuccess = 0,
    
    /**
     @brief No response was received from the reader.
     @details This only applies to the Shuttle reader.
     */
    SwipeActivationResultTimeout = 1,
    
    /**
     @brief Activation failed with no detailed message.
     @details This only applies to the Shuttle reader.
     @note This is included here for Android compatibility.  This message is never sent under iOS.
     */
    SwipeActivationResultFailure = 2,
    
    /**
     @brief The reader could not be activated because the mobile device volume is too low.
     @details This only applies to the Shuttle reader.
     */
    SwipeActivationResultVolumeTooLow = 3
};

/**
 @brief The possible results of an attempt to activate a swipe reader.
 */
typedef enum SwipeActivationResult SwipeActivationResult;
