// Import pebble library
#include <pebble.h>
  
// Declaration of elements
Window *window;
TextLayer *textLayer;
Layer *rootLayer;

void onClickSelect(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(textLayer, "onClickSelect");
}

void onClickUp(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(textLayer, "onClickUp");
}

void onClickDown(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(textLayer, "onClickDown");
}

void onClickBack(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(textLayer, "onClickBack");
}

void onClickLongSelectnStart(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(textLayer, "onClickLongSelectnStart");
}

void onClickLongSelectStop(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(textLayer, "onClickLongSelectStop");
}

void onClickMultiSelect(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(textLayer, "onClickMultiSelect");
}

void config_clicks(void *context) {
  // Single click
  window_single_click_subscribe(BUTTON_ID_SELECT, onClickSelect);
  window_single_click_subscribe(BUTTON_ID_UP, onClickUp);
  window_single_click_subscribe(BUTTON_ID_DOWN, onClickDown);
  window_single_click_subscribe(BUTTON_ID_BACK, onClickBack);
  
  // Custom clicks
  window_long_click_subscribe(BUTTON_ID_SELECT, 800 /*time*/, onClickLongSelectnStart, onClickLongSelectStop);
  window_multi_click_subscribe(BUTTON_ID_SELECT, 2 /*min_clicks*/, 10/*min_clicks*/, 0/*timeout_300ms*/, true/*last_click_only*/, onClickMultiSelect);
}


/**
* init()
* Initialize the app
*
*/
void init(void) {

	// Make a window and get pointer
	window = window_create();
	// Get root layer
	rootLayer = window_get_root_layer(window);
	// Create example layer
	textLayer = text_layer_create(GRect(0, 0, 144, 154));

	// Set text in the layer
	text_layer_set_text(textLayer, "Hellow World");
	// Set font type to the layer
	text_layer_set_font(textLayer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
	// Set aligment
	text_layer_set_text_alignment(textLayer, GTextAlignmentCenter);

	// Add the text layer to the window
	layer_add_child(rootLayer, text_layer_get_layer(textLayer));

	// Push the window
	window_stack_push(window, true);

  window_set_click_config_provider(window, config_clicks);

	// App Logging!
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}

/**
* deinit()
* Clear app
*
*/
void deinit(void) {

	// Destroy the text layer
	text_layer_destroy(textLayer);

	// Destroy the window
	window_destroy(window);
}

/**
* main()
* Basic app structure
*
*/
int main(void) {
	init();
	// Block in init if we are in the app
	app_event_loop();
	// Remove rubbish
	deinit();
}
