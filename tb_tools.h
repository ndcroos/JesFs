/*********************************************************************
* tb_tool.h - Toolbox for UART, Unix-Time, .. 
*
* 2019 (C) joembedded.de
* Version: 1.0 25.11.2019
*********************************************************************/

void tb_init(void);
void tb_uninit(void);

void tb_board_led_on(uint8_t idx); // LED mapper
void tb_board_led_off(uint8_t idx);
void tb_board_led_invert(uint8_t idx);

void tb_system_reset(void); // system reset

void tb_watchdog_init(void);  // Init Watchdog
void tb_watchdog_feed(uint32_t feed_ticks); // feed_ticks: currently no function, but >0

void tb_delay_ms(uint32_t msec); // --- Lower power delay than nrf_delay

uint32_t tb_get_ticks(void);
uint32_t tb_deltaticks_to_ms(uint32_t t0, uint32_t t1);

uint32_t tb_time_get(void); // ---- Unix-Timer. Must be called periodically to work, but at least twice per RTC-overflow ---
void tb_time_set(uint32_t new_secs); // Set time, regarding the timer

void tb_printf(char* fmt, ...); // tb_printf(): printf() to toolbox uart. Wait if busy
void tb_putc(char c); // tb_putc(): Wait if not ready
int16_t tb_kbhit(void); // ---- Input functions 0: Nothing available (tb_kbhit is faster than tb_getc) ---------
int16_t tb_getc(void); // ---- get 1 char (0..255) (or -1 if nothing available)
// Get String with Timout (if >0) in msec of infinite (Timout 0), No echo (max_uart_in without trailing \0!)
int16_t tb_gets(char* input, int16_t max_uart_in, uint16_t max_wait_ms, uint8_t echo);

//***

