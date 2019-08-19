#ifndef __OHGODATOOL_H
#define __OHGODATOOL_H

#include <stdint.h>
#include <stdbool.h>

#define OHGODATOOL_VERSION		"v1.4"

#ifdef __unix__
#define TEMP_SUPPORT		1
#define FANSPEED_SUPPORT	1
#endif

typedef struct _ArgsObj
{
	bool MemStateIdxProvided, CoreStateIdxProvided, SoCClkStateIdxProvided, SetMemClock, SetCoreClock, SetMemVDDCIdx, SetVTblVDD, SetFanspeed;
	bool GPUIdxProvided, VoltageStateIdxProvided, SetCoreVDDCIdx, SetVDDCI, SetSoCClock, SetMVDD, SetCoreVDDCOff, SetVDDCGFXOff;
	bool SetTDP, SetTDC, SetMaxPower, SetMaxCoreClk, SetMaxMemClk, VBIOSFileProvided;

	bool ShowMemStates, ShowCoreStates, ShowVoltageStates, ShowSoCCLKStates, ShowFanspeed, ShowTemp, ShowTDP, ShowTDC, ShowMaxPwr;
	bool ShowMaxCoreClk, ShowMaxMemClk, VDDCoreTbl, VDDMemTbl, VDDVDDCITbl;

	int32_t MemStateIdx, CoreStateIdx, VoltStateIdx, SoCClkStateIdx;
	uint32_t GPUIdx, ReqCoreClk, ReqMemClk, ReqVDDCI, ReqSoCCLK;
	uint32_t ReqMVDD, ReqCoreVoltTblIdx, ReqMemVoltTblIdx, ReqVoltTblVDDC, ReqFanspeedPercentage;
	uint32_t ReqTDP, ReqTDC, ReqMaxPower, ReqMaxCoreClk, ReqMaxMemClk;

	char *VBIOSFileName;

	int32_t ReqCoreVDDCOff, ReqVDDCGFXOff;
} ArgsObj;

bool ParseCmdLine(ArgsObj *Args, int argc, char **argv);

#endif

