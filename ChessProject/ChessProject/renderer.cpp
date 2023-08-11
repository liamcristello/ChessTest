/// <summary>
/// Draws a rectangle of the specified color, to the specified dimensions.
/// </summary>
/// <param name="x0">X-coordinate of top-left corner.</param>
/// <param name="y0">Y-coordinate of top-left corner.</param>
/// <param name="x1">X-coordinate of bottom-right corner.</param>
/// <param name="y1">Y-coordinate of bottom-right corner.</param>
/// <param name="color">Color value to fill rectangle with.</param>
internal void draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color) {
	x0 = clamp(x0, 0, render_state.width);
	x1 = clamp(x1, 0, render_state.width);
	y0 = clamp(y0, 0, render_state.height);
	y1 = clamp(y1, 0, render_state.height);

	/*if (x0 > x1) {
		swap(x0, x1);
	}
	if (y0 > y1) {
		swap(y0, y1);
	}*/

	for (int y = y0; y < y1; y++) {
		u32* pixel = (u32*)render_state.memory + x0 + y*render_state.width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}

global_variable float render_scale = 0.01f;

internal void draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color) {
	x *= render_state.height * render_scale;
	y *= render_state.height * render_scale;
	half_size_x *= render_state.height * render_scale;
	half_size_y *= render_state.height * render_scale;

	x += render_state.width / 2.f;
	y += render_state.height / 2.f;

	// Change to pixels
	int x0 = x - half_size_x;
	int x1 = x + half_size_x;
	int y0 = y - half_size_y;
	int y1 = y + half_size_y;

	draw_rect_in_pixels(x0, y0, x1, y1, color);
}

/// <summary>
/// Clears the entire screen, with a specified color.
/// </summary>
/// <param name="color">Color to fill the entire screen with</param>
internal void clear_screen(u32 color) {
	draw_rect_in_pixels(0, 0, render_state.width, render_state.height, color);
}