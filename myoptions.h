#ifndef myoptions_h
#define myoptions_h

/*
 * Конфигурация ehRadio для Freenove ESP32-S3 Display 2.8" (FNK0104B)
 * Аппаратное обеспечение: ESP32-S3 (16MB Flash / 8MB PSRAM)
 * Дисплей: ILI9341 240x320 IPS (SPI)
 * Тачскрин: FT6336G (I2C)
 * Аудио: ES8311 (I2S + I2C)
 */

// ==================== Язык ====================
#define L10N_LANGUAGE       RU

// ==================== Дисплей (ILI9341 SPI) ====================
#define DSP_MODEL           DSP_ILI9341
#define TFT_CS              10      // Chip Select
#define TFT_DC              46      // Data/Command
#define TFT_RST             -1      // Не подключён (общий с EN)
#define TFT_SCK             12      // SPI Clock
#define TFT_MOSI            11      // SPI Data Out
#define TFT_MISO            13      // SPI Data In (только для чтения)
#define BRIGHTNESS_PIN      45      // Подсветка (высокий уровень = вкл)
#define TFT_IPS             1       // IPS-панель требует инверсии цветов

// ==================== Тачскрин (FT6336G I2C) ====================
#define TS_MODEL            TS_MODEL_FT6336
#define TS_SDA              16
#define TS_SCL              15
#define TS_INT              17
#define TS_RST              18

// ==================== Аудио (ES8311) ====================
// Внутренний DAC/AMP — закомментирован (не используется на этой плате)
// #define I2S_DOUT         41
// #define I2S_BCLK         42
// #define I2S_LRC          2

// Внешний кодек ES8311
#define I2S_DOUT            8       // Данные от ESP32 к ES8311
#define I2S_BCLK            5       // Bit Clock
#define I2S_LRC             7       // Left/Right Clock (WS)
#define I2S_MCLK            4       // Master Clock (ES8311 требует MCLK)

// Управление кодеком через I2C (разделяет шину с тачскрином)
#define AUDIO_CODEC_I2C_SDA 16
#define AUDIO_CODEC_I2C_SCL 15
#define AUDIO_CODEC_PA_PIN  1       // Усилитель FM8002E (низкий уровень = вкл)

// ==================== SD-карта (SDIO 4-bit) ====================
// ehRadio в основном использует SPI для SD. Если вы не используете офлайн-функции,
// можно оставить закомментированным, чтобы не мешать компиляции.
// Если нужно — раскомментируйте и проверьте поддержку SDIO в вашей версии ehRadio.
// #define SDC_CS           10
// #define SD_HSPI          true
// #define SD_SPIPINS       12, 13, 11

// ==================== IR / Кнопки ====================
// IR-приёмник (если установлен)
// #define IR_PIN            6
// #define IR_TIMEOUT        15
// #define DECODE_HASH       false

// ==================== Прочие настройки ====================
#define PLAYER_FORCE_MONO   true    // Один динамик — принудительное моно
#define NO_VOLUME_SCREEN            // Отключить экран громкости (по желанию)
// #define VU_PEAK                  // Включить VU-метр (по желанию)

// Энергосбережение
#define POWER_SAVE          2       // 0=выкл, 1=только сон, 2=всегда
#define WAKEUP_REBOOT               // Перезагрузка при пробуждении

// Часы / TTS (отключено)
#define CLOCK_TTS_ENABLED   false

// Автояркость (если есть датчик света — на этой плате нет, оставьте закомментированным)
// #define LIGHT_SENSOR      5
// #define AUTOBACKLIGHT_DARK  4000
// #define AUTOBACKLIGHT_BRI   100
// #define AUTOBACKLIGHT_MIN   20

#endif
