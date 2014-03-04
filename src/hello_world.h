// Import pebble library
#include <pebble.h>
  
// Declaration of elements
Window *window;
TextLayer *textLayer;
Layer *rootLayer;

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
