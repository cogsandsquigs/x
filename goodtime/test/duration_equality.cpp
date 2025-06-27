#include "Goodtime.h"
#include "unity.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void duration_secs_eq_1000_millis() {
    Duration d1 = Duration::from_millis(123000);
    Duration d2 = Duration::from_secs(123);
    TEST_ASSERT_TRUE(d1 == d2);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(duration_secs_eq_1000_millis);

    return UNITY_END();
}
