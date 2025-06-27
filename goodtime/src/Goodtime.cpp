#include "Goodtime.h"

/// The global, private variable we use to "track" the time.
/// WARN: SHOULD BE PRIVATE! NO ONE SHOULD EVER TOUCH THIS BUT US!
static volatile int32_t _millis;

// ISR to interrupt on timer0 overflow. Since this happens every 1/250 ms, we
// check the timer0 counter and increment the millis variable accordingly.
// WARN: The timer0 counter overflows at 256, but we need to check only when
// it's at 250.
// TODO: make this!!!

// Duration code!

Duration Duration::from_millis(int32_t millis) {
    // Create a duration from a number of millis.
    Duration duration;
    // Set the duration to the given millis.
    duration._duration_millis = millis;
    // Return the duration.
    return duration;
}

Duration Duration::from_secs(int32_t seconds) {
    return Duration::from_millis(seconds * 1000);
}

Duration Duration::add_millis(int32_t x) {
    // Create a new duration that is the sum of this duration and the given
    // millis.
    Duration duration;
    // Set the duration to the sum of this duration and the given millis.
    duration._duration_millis = _duration_millis + x;
    // Return the new duration.
    return duration;
}

Duration Duration::add_secs(int32_t x) { return this->add_millis(x * 1000); }

Duration Duration::add_duration(Duration x) {
    return this->add_millis(x._duration_millis);
}

Duration Duration::operator+(const Duration &x) {
    return this->add_duration(x);
}

/* Comparison code!*/

bool Duration::operator==(const Duration &x) const {
    // Compare the two durations to see if they are equal.
    return _duration_millis == x._duration_millis;
}

bool Duration::operator!=(const Duration &x) const {
    // Compare the two durations to see if they are not equal.
    return _duration_millis != x._duration_millis;
}

bool Duration::operator>(const Duration &x) const {
    // Compare the two durations to see if this duration is greater than the
    // given duration.
    return _duration_millis > x._duration_millis;
}

bool Duration::operator<(const Duration &x) const {
    // Compare the two durations to see if this duration is less than the given
    // duration.
    return _duration_millis < x._duration_millis;
}

bool Duration::operator>=(const Duration &x) const {
    // Compare the two durations to see if this duration is greater than or
    // equal to the given duration.
    return _duration_millis >= x._duration_millis;
}

bool Duration::operator<=(const Duration &x) const {
    // Compare the two durations to see if this duration is less than or equal
    // to the given duration.
    return _duration_millis <= x._duration_millis;
}

// Instant code!

Instant Instant::now() {
    // Create an instant that represents the time right now.
    Instant instant;
    // Set the instant to the current time.
    instant._instant_millis = _millis;
    // Return the instant.
    return instant;
}

Duration Instant::elapsed() {
    // Create a duration that represents the time since this instant was
    // created.
    Duration duration;
    // Set the duration to the difference between the current time and this
    // instant.
    duration.add_millis(_millis - _instant_millis);
    // Return the duration.
    return duration;
}

/* Comparison code!*/

bool Instant::operator==(const Instant &x) const {
    // Compare the two instants to see if they are equal.
    return _instant_millis == x._instant_millis;
}

bool Instant::operator!=(const Instant &x) const {
    // Compare the two instants to see if they are not equal.
    return _instant_millis != x._instant_millis;
}

bool Instant::operator>(const Instant &x) const {
    // Compare the two instants to see if this instant is greater than the
    // given instant.
    return _instant_millis > x._instant_millis;
}

bool Instant::operator<(const Instant &x) const {
    // Compare the two instants to see if this instant is less than the given
    // instant.
    return _instant_millis < x._instant_millis;
}

bool Instant::operator>=(const Instant &x) const {
    // Compare the two instants to see if this instant is greater than or equal
    // to the given instant.
    return _instant_millis >= x._instant_millis;
}

bool Instant::operator<=(const Instant &x) const {
    // Compare the two instants to see if this instant is less than or equal to
    // the given instant.
    return _instant_millis <= x._instant_millis;
}
