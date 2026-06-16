<div align="center">

# TFT-AutoProbe

**Mini-Diagnose-Firmware zum schnellen Verifizieren eines TFT_eSPI-Setups** (Init / Rotation / Backlight) auf ESP32.

[![Plattform](https://img.shields.io/badge/Plattform-ESP32-blue?style=flat-square)](.)
[![Build](https://img.shields.io/badge/Build-PlatformIO-orange?style=flat-square&logo=platformio)](https://platformio.org)
[![Display](https://img.shields.io/badge/Display-ST7789%20240x320-green?style=flat-square)](.)
[![Lizenz](https://img.shields.io/badge/Lizenz-MIT-green?style=flat-square)](LICENSE)

</div>

---

Lädt das Display, schaltet die Hintergrundbeleuchtung ein und zeigt einen Testtext — ideal, um nach dem Verdrahten oder bei neuem Board in Sekunden zu prüfen, ob Pins, Treiber und Backlight stimmen.

## Hardware

| Parameter | Wert |
|-----------|------|
| MCU | ESP32 (`esp32dev`) |
| Display-Treiber | ST7789, 240×320 |
| SPI-Pins | MOSI 13 · SCLK 14 · MISO 12 · CS 15 · DC 2 · RST −1 |
| Backlight | GPIO 21 (aktiv HIGH) |

Die Display-Konfiguration ist in `platformio.ini` als `build_flags` gepflegt (entspricht `src/TFT_AutoProbe/tft_setup.h` für Arduino-IDE-Nutzer).

## Fertige Firmware

Vorkompiliertes, flashfertiges Image unter [**Releases**](https://github.com/G4MEOVER18/TFT-AutoProbe/releases/latest):

```bash
esptool.py --chip esp32 write_flash 0x0 TFT-AutoProbe_esp32dev_v1.0.0_merged.bin
```

## Selbst bauen (PlatformIO)

```bash
pio run                       # bauen
pio run -t upload             # flashen
pio device monitor -b 115200  # serielle Ausgabe
```

PlatformIO lädt automatisch die **gepinnten** Abhängigkeiten (espressif32 6.9.0, TFT_eSPI 2.5.43) — reproduzierbar, ohne Breaking Changes durch Library-Updates. Details: [`docs/DEPENDENCIES.md`](docs/DEPENDENCIES.md).

### Alternative: Arduino IDE

Sketch `src/TFT_AutoProbe/TFT_AutoProbe.ino` öffnen, TFT_eSPI installieren, Board **ESP32 Dev Module** wählen, flashen. Das Display-Setup kommt aus `tft_setup.h`.

## Projektstruktur

- `src/TFT_AutoProbe/` – Sketch + `tft_setup.h`
- `docs/` – Abhängigkeiten & Hinweise
- `legacy/` – ursprünglicher Import (Referenz)

## Lizenz

MIT – siehe [LICENSE](LICENSE). © 2026 Yanis Ameseder

---

## Kontakt

**Entwickler:** Yanis Ameseder · **E-Mail:** [g4me.over.18@gmail.com](mailto:g4me.over.18@gmail.com)
