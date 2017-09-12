
/**
 @brief Represents the type of audio jack-connected reader that the PGSwipeController should support.
 */
typedef enum AudioJackReaderType
{
    /**
     @brief Represents a UniMag (Shuttle) card reader.
     */
    AudioJackReaderUnimag = 1,

    
    /**
     @brief Represents an IPS card reader.
     */
    AudioJackReaderIps = 2,

    /**
     @brief When set as the PGSwipeController's audio jack reader type, a call to beginAutodetectAudioJackCardReader is made when an object is attached to the audio jack.
     @details On completion, the PGSwipeController's card reader type is set to the detected type, or AudioJackReaderNone if the autodetect failed.
     @note See PGSwipeController's documentation for warnings about using beginAutodetectAudioJackCardReader.
     */
    AudioJackReaderAutodetectOnConnect = 3,
    
    /**
     @brief When set as the PGSwipeController's audio jack reader type, the PGSwipeController will not attempt to support any audio jack-connected readers.
     @details To enable audio jack reader support, set the reader type to Unimag or Ips, or call the PGSwipeController's beginAutodetectAudioJackCardReader to detect the device.
     @note Before beginAutodetectAudioJackCardReader will succeed, the device must be attached.  You may add your class as a delegate of [PGAudioJackConnectionDetector defaultDetector] to be notified when devices are attached and detached from the audio port.
     @note See PGSwipeController's documentation for warnings about using beginAutodetectAudioJackCardReader.
     */
    AudioJackReaderNone = 4,
    
    /**
     @brief Represents an IpsEnterprise card reader.
     */
    AudioJackReaderIpsEnterprise = 5,
    
} AudioJackReaderType;
