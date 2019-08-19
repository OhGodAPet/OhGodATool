// Copyright (c) 2017 OhGodACompany - OhGodAGirl & OhGodAPet

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#ifdef __linux__

// Must be freed by caller unless NULL
void GetGPUHWMonPath(char **HWMonPath, uint32_t GPUIdx)
{
	DIR *hwmon;
	char TempPath[256];
	struct dirent *inner_hwmon;
	
	// Set it to NULL (indicating failure) until we need to use it
	*HWMonPath = NULL;
	
	sprintf(TempPath, "/sys/class/drm/card%d/device/hwmon", GPUIdx);
	
	hwmon = opendir(TempPath);
	
	if(!hwmon)
	{
		printf("Unable to open hwmon dir for GPU %d.\n", GPUIdx);
		return;
	}
	
	for(;;)
	{
		inner_hwmon = readdir(hwmon);
		if(!inner_hwmon) break;
		
		if(inner_hwmon->d_type != DT_DIR) continue;
		
		if(!memcmp(inner_hwmon->d_name, "hwmon", 5)) break;
	}
	
	if(!inner_hwmon)
	{
		printf("Unable to open hwmon dir for GPU %d.\n", GPUIdx);
		return;
	}
	
	*HWMonPath = (char *)malloc(sizeof(char) * (256 + strlen(inner_hwmon->d_name)));
	sprintf(*HWMonPath, "/sys/class/drm/card%d/device/hwmon/%s", GPUIdx, inner_hwmon->d_name);
	return;
}

#endif
