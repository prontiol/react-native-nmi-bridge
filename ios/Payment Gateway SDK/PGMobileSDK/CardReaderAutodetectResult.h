

/**
 @brief The result of an attempt to detect the device type for an audio-jack connected card reader.
 */
typedef enum CardReaderAutodetectResult
{

    /**
     @brief A UniMag (Shuttle) device was detected.
     */
    CardReaderAutodetectResultUniMag,

    
    /**
     @brief An IPS device was detected
     */
    CardReaderAutodetectResultIps,

    /**
     @brief An IpsEnterprise device was detected
     */
    CardReaderAutodetectResultIpsEnterprise,
    
    /**
     @brief The type of device could not be determined.  The device may be malfunctioning, may have been removed during detection, or may not be one of the supported card reader types.
     */
    CardReaderAutodetectResultFail

    
} CardReaderAutodetectResult;

