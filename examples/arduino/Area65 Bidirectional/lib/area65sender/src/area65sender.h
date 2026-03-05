#ifndef Area65Sender_h
#define Area65Sender_h

#include <Arduino.h>
#include <SoftwareSerial.h>

/**
 * @brief Maximum number of P-values that can be transmitted in a single JSON payload.
 * 
 * This constant defines the upper limit for the numValues parameter in sendData().
 * Values beyond this limit will result in an error response.
 */
#define MAX_VALUES 20

/**
 * @brief Default minimum delay between consecutive JSON transmissions in milliseconds.
 * 
 * This constant establishes the default rate-limiting interval to prevent serial port
 * congestion. The actual delay can be customized using setDelay().
 */
#define MIN_SEND_DELAY 2000

/**
 * @brief Default baud rate for SoftwareSerial transmission.
 * 
 * This constant defines the default serial communication speed used by the library
 * for JSON transmission via SoftwareSerial.
 */
#define DEFAULT_SERIAL_BAUD 57600

/**
 * @class Area65Sender
 * @brief A professional-grade library for transmitting multi-parameter data as JSON
 *        via SoftwareSerial on Arduino platforms.
 * 
 * This library provides a robust interface for sending up to 20 floating-point values
 * (P1-P20) in a structured JSON format. It features automatic decimal formatting,
 * rate-limiting to prevent serial port flooding, and flexible parameter handling
 * through variadic arguments.
 * 
 * @par Features
 * - Dynamic parameter count (1-20 values per transmission)
 * - Automatic 2-decimal-place formatting of all numerical values
 * - Built-in rate limiting with configurable delay
 * - JSON output format: {"P1":value1,"P2":value2,...,"P20":value20}
 * - Error handling for invalid parameter counts
 * - Non-blocking delay implementation using millis()
 * - Automatic SoftwareSerial initialization
 * 
 * @par Example Usage
 * @code
 * #include <Arduino.h>
 * #include <SoftwareSerial.h>
 * #include <area65sender.h>
 * 
 * SoftwareSerial mySerial(10, 11);
 * Area65Sender sender(mySerial);
 * 
 * void setup() {
 *   Serial.begin(115200);
 *   // mySerial is automatically initialized with DEFAULT_SERIAL_BAUD
 * }
 * 
 * void loop() {
 *   // Send single value (P1 only)
 *   sender.sendData(1, 12.34);
 *   
 *   // Send multiple values (P1, P2, P3)
 *   sender.sendData(3, 1.5, 2.5, 3.5);
 *   
 *   // Send all 20 values
 *   sender.sendData(20, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
 *                   10.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
 *   
 *   delay(2000);
 * }
 * @endcode
 */
class Area65Sender {
  public:
    /**
     * @brief Constructs an Area65Sender instance.
     * 
     * Initializes the sender with the specified SoftwareSerial object for
     * JSON transmission. The internal delay is set to MIN_SEND_DELAY (2000ms)
     * by default and the SoftwareSerial port is automatically initialized
     * with DEFAULT_SERIAL_BAUD (57600).
     * 
     * @param serial Reference to a SoftwareSerial object. The caller should
     *        configure the pin assignments before passing the object, but
     *        initialization (begin()) is handled automatically by this library.
     */
    Area65Sender(SoftwareSerial& serial);
    
    /**
     * @brief Transmits a single value as P1 in JSON format.
     * 
     * This method accepts one floating-point value and transmits it as P1.
     * All values are automatically formatted to 2 decimal places.
     * 
     * @param firstValue The floating-point value to transmit as P1.
     * @return true if transmission was successful (or skipped due to rate limiting).
     * @note This method is primarily for internal use. Use sendData(int, ...) for
     *       explicit control over parameter count.
     */
    bool sendData(float firstValue, ...);
    
    /**
     * @brief Transmits 1-20 values as P1-P20 in JSON format.
     * 
     * This variadic method accepts a specified number of floating-point values
     * and transmits them as P1 through P20 in a JSON object. All numerical values
     * are automatically converted to 2 decimal places. The method implements
     * rate limiting to prevent serial port congestion.
     * 
     * @param numValues The number of values to transmit (must be 1-20).
     * @param ... Variable number of floating-point values to transmit.
     * @return true if transmission was successful, false if numValues is invalid.
     * 
     * @par Error Handling
     * - Returns false and logs error message if numValues < 1 or numValues > 20
     * - Rate limiting may cause actual transmission to be skipped (returns true)
     * 
     * @par Example
     * @code
     * sender.sendData(3, 1.5, 2.5, 3.5);  // Sends {"P1":1.50,"P2":2.50,"P3":3.50}
     * @endcode
     */
    bool sendData(int numValues, ...);
    
    /**
     * @brief Configures the minimum delay between consecutive JSON transmissions.
     * 
     * This method allows customization of the rate-limiting interval. The default
     * delay is 2000ms (MIN_SEND_DELAY). Setting a shorter delay increases the
     * transmission rate but may cause serial port congestion.
     * 
     * @param milliseconds The minimum delay between transmissions in milliseconds.
     *        Valid range: 0 (no delay) to any positive integer.
     *        Values outside this range are clamped to the valid range.
     * 
     * @par Implementation Notes
     * - Uses non-blocking millis() for delay tracking
     * - Calls within the delay window are silently skipped
     * - The delay is measured from the last successful transmission
     */
    void setDelay(int milliseconds);

  private:
    /**
     * @brief Pointer to the SoftwareSerial object used for JSON transmission.
     */
    SoftwareSerial* _serial;
    
    /**
     * @brief Internal buffer storing the current P1-P20 values.
     * 
     * This array holds up to MAX_VALUES floating-point values that are
     * prepared for JSON transmission. Values are copied from variadic
     * arguments during each sendData() call.
     */
    float _values[MAX_VALUES];
    
    /**
     * @brief Timestamp of the last successful JSON transmission in milliseconds.
     * 
     * This value is used in conjunction with millis() to implement rate
     * limiting. It is updated each time a JSON payload is successfully
     * transmitted.
     */
    unsigned long _lastSendTime;
    
    /**
     * @brief Current minimum delay between transmissions in milliseconds.
     * 
     * This value is initialized to MIN_SEND_DELAY but can be customized
     * via setDelay(). It determines the minimum interval between
     * successful transmissions.
     */
    int _minDelay;
    
    /**
     * @brief Builds and transmits a JSON payload with the specified number of values.
     * 
     * This private helper method constructs the JSON string from the internal
     * _values array and transmits it via the configured SoftwareSerial port.
     * It also outputs the same JSON to the hardware Serial port for debugging.
     * 
     * @param numValues The number of valid values in the _values array to include
     *        in the JSON payload (must be 1-20).
     * 
     * @par JSON Format
     * The output format is: {"P1":X.XX,"P2":X.XX,...,"Pn":X.XX}
     * where n is numValues and each value is formatted to 2 decimal places.
     */
    void sendJson(int numValues);
};

#endif
