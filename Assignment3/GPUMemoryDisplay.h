#pragma once
//GPUMemoryDisplay.h

class GPUMemoryDisplay : public Display
{
	string shader;
public:
	GPUMemoryDisplay(int x, int y, int duration, char* name, string shader) :Display(x, y, duration, name), shader(shader) {};
	GPUMemoryDisplay(const GPUMemoryDisplay& RGPUMD) :shader(RGPUMD.shader), Display(RGPUMD) {}
	string GetShader() { return shader; }
	int BufferSize() { return pixel_x*pixel_y * sizeof(float); }
};