
#ifndef __GOODTIME_H
#define __GOODTIME_H

#include <stdint.h>

// Check what board we are running on.
//  - If we're running on any arduino board, include the Arduino library and
//  define `__GOODTIME_B_ARDUINO`.
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO) ||                   \
    defined(ARDUINO_AVR_MEGA2560) || defined(ARDUINO_AVR_MICRO)
#include "Arduino.h"
#define __GOODTIME_B_ARDUINO
#else
// TODO: What if not arduino???
#endif

class Duration {
public:
    /// From a number of millis.
    /// @param `millis` The number of millis to create the `Duration` from.
    /// @returns The `Duration` that represents the given number of millis.
    static Duration from_millis(int32_t millis);

    /// From a number of seconds.
    /// @param `seconds` The number of seconds to create the `Duration` from.
    /// @returns The `Duration` that represents the given number of seconds.
    static Duration from_secs(int32_t seconds);

    /// Adds `x` millis to this `Duration`.
    /// @param `x` The number of millis to add to this `Duration`.
    Duration add_millis(int32_t x);

    /// Adds `x` seconds to this `Duration`.
    /// @param `x` The number of seconds to add to this `Duration`.
    Duration add_secs(int32_t x);

    /// Adds a duration to this `Duration`.
    /// @param `x` The duration to add to this `Duration`.
    Duration add_duration(Duration x);

    /// Adds a duration to this `Duration`.
    /// @param `x` The `Duration` to add to this `Duration`.
    Duration operator+(const Duration &x);

    /* Comparison stuffs! */

    /// Compares two `Duration`s to see if they are equal.
    bool operator==(const Duration &x) const;

    /// Compares two `Duration`s to see if they are not equal.
    bool operator!=(const Duration &x) const;

    /// Compares two `Duration`s to see if this duration is greater than the
    /// other
    bool operator>(const Duration &x) const;

    /// Compares two `Duration`s to see if this duration is less than the
    /// other
    bool operator<(const Duration &x) const;

    /// Compares two `Duration`s to see if this duration is greater than or
    /// equal to the other one.
    bool operator>=(const Duration &x) const;

    /// Compares two `Duration`s to see if this duration is less than or equal
    /// to the other one.
    bool operator<=(const Duration &x) const;

private:
    // The number of milliseconds that make up this `Duration`.
    int32_t _duration_millis;
};

// A singular, monotonically increasing time unit that represents the time at an
// instant. NOTE: You cannot access the inner timestamp of this class. This is
// to prevent you from accidentially comparing the time of two different
// instants directly, and instead only use safe calls.
class Instant {
public:
    /// Gets the instant that represents the time right now!
    /// @returns the `Instant` that represents the time right now.
    static Instant now();

    /// Gets the elapsed time since this `Instant` was created.
    Duration elapsed();

    /* Comparison stuffs! */

    /// Compares two `Instant`s to see if they are equal.
    /// @param `x` The instant to compare this instant to.
    bool operator==(const Instant &x) const;

    /// Compares two `Instant`s to see if they are not equal.
    /// @param `x` The instant to compare this instant to.
    bool operator!=(const Instant &x) const;

    /// Compares two `Instant`s to see if this instant is greater than the
    /// other
    /// @param `x` The instant to compare this instant to.
    bool operator>(const Instant &x) const;

    /// Compares two `Instant`s to see if this instant is less than the other
    /// one.
    /// @param `x` The instant to compare this instant to.
    bool operator<(const Instant &x) const;

    /// Compares two `Instant`s to see if this instant is greater than or equal
    /// to the other one.
    /// @param `x` The instant to compare this instant to.
    bool operator>=(const Instant &x) const;

    /// Compares two `Instant`s to see if this instant is less than or equal
    /// to the other one.
    /// @param `x` The instant to compare this instant to.
    bool operator<=(const Instant &x) const;

private:
    // The number of milliseconds that have passed at the moment this `Instant`
    // was created. Essentially, the "time" this instant was created.
    int32_t _instant_millis;
};

#endif
