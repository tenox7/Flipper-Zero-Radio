#pragma once

#include <gui/gui.h>
#include <gui/view_port.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/variable_item_list.h>
#include <gui/modules/text_input.h>
#include <subghz/devices/devices.h>

typedef enum {
    RadioScannerViewScanner,
    RadioScannerViewSettings,
    RadioScannerViewTextInput,
} RadioScannerView;

typedef enum {
    ScanDirectionUp,
    ScanDirectionDown,
} ScanDirection;

typedef enum {
    ModulationOok270,
    ModulationOok650,
    Modulation2FSKDev238,
    Modulation2FSKDev476,
    ModulationCount
} ModulationType;

typedef struct {
    Gui* gui;
    ViewPort* view_port;
    ViewDispatcher* view_dispatcher;
    VariableItemList* variable_item_list;
    TextInput* text_input;
    FuriMessageQueue* event_queue;
    bool running;
    uint32_t frequency;
    uint32_t frequency_step;
    float rssi;
    float sensitivity;
    bool scanning;
    ScanDirection scan_direction;
    ModulationType modulation;
    const SubGhzDevice* radio_device;
    bool speaker_acquired;
    char text_buffer[32];
} RadioScannerApp;

RadioScannerApp* radio_scanner_app_alloc(void);
void radio_scanner_app_free(RadioScannerApp* app);
int32_t radio_scanner_app(void* p);
