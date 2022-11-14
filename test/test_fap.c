#include <furi.h>

int32_t test_fap_app(void *p) {
  UNUSED(p);
  FURI_LOG_I("TEST", "Hello world");
  FURI_LOG_I("TEST",
  "I'm test_fap!");

  return 0;
}
