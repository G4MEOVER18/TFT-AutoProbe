# Abhängigkeiten

Reproduzierbarer Build über **PlatformIO** — alle Versionen sind in
`platformio.ini` gepinnt, damit Library-Updates den Build nicht brechen.

| Abhängigkeit | Gepinnte Version | Zweck |
|--------------|------------------|-------|
| Plattform `espressif32` | `6.9.0` | ESP32 Arduino-Core-Toolchain |
| Framework | `arduino` | Arduino-API |
| `bodmer/TFT_eSPI` | `2.5.43` | Display-Treiber (ST7789) |

## Display-Konfiguration

TFT_eSPI wird **nicht** über `User_Setup.h` der Library konfiguriert, sondern
projektlokal über `build_flags` in `platformio.ini` (`-DUSER_SETUP_LOADED=1`
plus Pin-/Treiber-Defines). Das hält die Library unverändert und den Build
selbsterklärend.

Für Arduino-IDE-Nutzer liegt dieselbe Konfiguration in
`src/TFT_AutoProbe/tft_setup.h`.

## Toolchain

- PlatformIO Core (`pip install platformio`) oder die VS-Code-Erweiterung.
- Beim ersten `pio run` werden Toolchain und Libraries automatisch geladen.
