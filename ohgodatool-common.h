#ifndef __OHGODATOOL_COMMON_H
#define __OHGODATOOL_COMMON_H

#include <stdint.h>

#pragma pack(push, 1)

typedef struct _AtomBIOSCommonTableHeader
{
	uint16_t Size;
	uint8_t FormatRevision;
	uint8_t TableContentRevision;
} AtomBIOSCommonTableHeader;

typedef struct _PPTableHeader
{
	AtomBIOSCommonTableHeader CommonTblHdr;			// Offset: 0x00

	uint8_t DataRevision;							// Offset: 0x04
	uint16_t DataSize;								// Offset: 0x05

	uint32_t GoldenPPID;							// Offset: 0x07
	uint32_t GoldenRevision;						// Offset: 0x0B
	uint16_t FormatID;								// Offset: 0x0F

	uint16_t VoltageTimeInus;						// Offset: 0x11
	uint32_t PlatformCapabilities;					// Offset: 0x13

	uint32_t MaxODCoreClk;							// Offset: 0x17
	uint32_t MaxODMemClk;							// Offset: 0x1A
	uint16_t PowerControlLimit;						// Offset: 0x1E
	uint16_t UlvVoltageOffset;						// Offset: 0x20

	// Table locations (offsets)
	uint16_t StateArrayOffset;						// Offset: 0x22
	uint16_t FanTableOffset;						// Offset: 0x24
	uint16_t ThermalControlOffset;					// Offset: 0x26
	uint16_t Reserved0;								// Offset: 0x28
	uint16_t MemClkDepTableOffset;					// Offset: 0x2A
	uint16_t CoreClkDepTableOffset;
	uint16_t VDDCLookupTableOffset;
	uint16_t VDDCGFXLookupTableOffset;
	uint16_t MMDependencyTableOffset;
	uint16_t VCEStateTableOffset;
	uint16_t PPMTableOffset;
	uint16_t PowerTuneTableOffset;
	uint16_t HardLimitTableOffset;
	uint16_t PCIETableOffset;
	uint16_t GPIOTableOffset;
	uint16_t Reserved1[6];
} PPTableHeader;

typedef struct _Vega10PPTableHeader
{
	AtomBIOSCommonTableHeader CommonTblHdr;

	uint8_t DataRevision;
	uint16_t DataSize;

	uint32_t GoldenPPID;
	uint32_t GoldenRevision;
	uint16_t FormatID;
	uint32_t PlatformCapabilities;

	uint32_t MaxODCoreClk;
	uint32_t MaxODMemClk;
	uint16_t PowerControlLimit;
	uint16_t UlvVoltageOffset;
	uint16_t UlvSmnclkDid;
	uint16_t UlvMp1clkDid;
	uint16_t UlvGfxclkBypass;
	uint16_t GfxClkSlewRate;
	uint8_t GfxVoltageMode;
	uint8_t SocVoltageMode;
	uint8_t UclkVoltageMode;
	uint8_t UvdVoltageMode;
	uint8_t VceVoltageMode;
	uint8_t Mp0VoltageMode;
	uint8_t DcefVoltageMode;

	uint16_t StateArrayOffset;
	uint16_t FanTableOffset;
	uint16_t ThermalControlOffset;
	uint16_t SocClkDependencyTableOffset;
	uint16_t MemClkDepTableOffset;
	uint16_t GFXClkDependencyTableOffset;
	uint16_t DcefClkDependencyTableOffset;
	uint16_t VDDCLookupTableOffset;
	uint16_t VDDMemLookupTableOffset;
	uint16_t MMDependencyTableOffset;
	uint16_t VCEStateTableOffset;
	uint16_t Reserved;
	uint16_t PowerTuneTableOffset;
	uint16_t HardLimitTableOffset;
	uint16_t VDDCILookupTableOffset;
	uint16_t PCIETableOffset;
	uint16_t PixClkDependencyTableOffset;
	uint16_t DispClkDependencyTableOffset;
	uint16_t PhyClkDependencyTableOffset;
} Vega10PPTableHeader;

typedef struct _Vega10VoltageLookupRecord
{
	uint16_t VDD;
} Vega10VoltageLookupRecord;

typedef struct _Vega10VoltageLookupTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	Vega10VoltageLookupRecord Entries[1];
} Vega10VoltageLookupTable;

typedef struct _VegaClkDepRecord
{
	uint32_t Clock;
	uint8_t VDDCIndex;
} VegaClkDepRecord;

typedef struct _Vega10SOCClkDepTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	VegaClkDepRecord Entries[1];
} Vega10SOCClkDepTable;

typedef struct _Vega10GFXClkDepRecordV1
{
	uint32_t Clock;
	uint8_t VDDCIdx;
	uint16_t CKSVOffsetandDisable;
	uint16_t AVFSOffset;
} Vega10GFXClkDepRecordV1;

typedef struct _Vega10GFXClkDepRecordV2
{
	uint32_t Clock;
	uint8_t VDDCIdx;
	uint16_t CKSVOffsetandDisable;
	uint16_t AVFSOffset;
	uint8_t ACGEnable;
	uint8_t Reserved[3];
} Vega10GFXClkDepRecordV2;

typedef struct _Vega10GFXClkDepTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	Vega10GFXClkDepRecordV1 Entries[1];
} Vega10GFXClkDepTable;

typedef struct _Vega10MemClkDepRecord
{
	uint32_t MemClk;
	uint8_t VDDCIdx;
	uint8_t MVDDCIdx;
	uint8_t VDDCIIdx;
} Vega10MemClkDepRecord;

typedef struct _Vega10MemClkDepTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	Vega10MemClkDepRecord Entries[1];
} Vega10MemClkDepTable;

// RevId == 5
typedef struct _Vega10PowerTuneTableV1
{
	uint8_t RevId;
	uint16_t SocketPowerLimit;
	uint16_t BatteryPowerLimit;
	uint16_t SmallPowerLimit;
	uint16_t TDCLimit;
	uint16_t EDCLimit;
	uint16_t SoftwareShutdownTemp;
	uint16_t TemperatureLimitHotspot;
	uint16_t TemperatureLimitLiquid1;
	uint16_t TemperatureLimitLiquid2;
	uint16_t TemperatureLimitHBM;
	uint16_t TemperatureLimitVrSoc;
	uint16_t TemperatureLimitVrMem;
	uint16_t TemperatureLimitPlx;
	uint16_t LoadLineResistance;
	uint8_t Liquid1_I2C_Address;
	uint8_t Liquid2_I2C_Address;
	uint8_t Vr_I2C_Address;
	uint8_t Plx_I2C_Address;
	uint8_t Liquid_I2C_LineSCL;
	uint8_t Liquid_I2C_LineSDA;
	uint8_t Vr_I2C_LineSCL;
	uint8_t Vr_I2C_LineSDA;
	uint8_t Plx_I2C_LineSCL;
	uint8_t Plx_I2C_LineSDA;
	uint16_t TemperatureLimitTedge;
} Vega10PowerTuneTableV1;

// RevId == 6
typedef struct _Vega10PowerTuneTableV2
{
	uint8_t RevId;
	uint16_t SocketPowerLimit;
	uint16_t BatteryPowerLimit;
	uint16_t SmallPowerLimit;
	uint16_t TDCLimit;
	uint16_t EDCLimit;
	uint16_t SoftwareShutdownTemp;
	uint16_t TemperatureLimitHotspot;
	uint16_t TemperatureLimitLiquid1;
	uint16_t TemperatureLimitLiquid2;
	uint16_t TemperatureLimitHBM;
	uint16_t TemperatureLimitVrSoc;
	uint16_t TemperatureLimitVrMem;
	uint16_t TemperatureLimitPlx;
	uint16_t LoadLineResistance;
	uint8_t Liquid1_I2C_Address;
	uint8_t Liquid2_I2C_Address;
	uint8_t Liquid_I2C_Line;
	uint8_t Vr_I2C_Address;
	uint8_t Vr_I2C_Line;
	uint8_t Plx_I2C_Address;
	uint8_t Plx_I2C_Line;
	uint16_t TemperatureLimitTedge;
} Vega10PowerTuneTableV2;

// RevId == 7
typedef struct _Vega10PowerTuneTableV3
{
	uint8_t RevId;
	uint16_t SocketPowerLimit;
	uint16_t BatteryPowerLimit;
	uint16_t SmallPowerLimit;
	uint16_t TDCLimit;
	uint16_t EDCLimit;
	uint16_t SoftwareShutdownTemp;
	uint16_t TemperatureLimitHotspot;
	uint16_t TemperatureLimitLiquid1;
	uint16_t TemperatureLimitLiquid2;
	uint16_t TemperatureLimitHBM;
	uint16_t TemperatureLimitVrSoc;
	uint16_t TemperatureLimitVrMem;
	uint16_t TemperatureLimitPlx;
	uint16_t LoadLineResistance;
	uint8_t Liquid1_I2C_Address;
	uint8_t Liquid2_I2C_Address;
	uint8_t Liquid_I2C_Line;
	uint8_t Vr_I2C_Address;
	uint8_t Vr_I2C_Line;
	uint8_t Plx_I2C_Address;
	uint8_t Plx_I2C_Line;
	uint16_t TemperatureLimitTedge;
	uint16_t BoostStartTemperature;
	uint16_t BoostStopTemperature;
	uint32_t BoostClock;
	uint32_t Reserved[2];
} Vega10PowerTuneTableV3;

typedef struct _PolarisPowerTuneTable
{
	uint8_t RevId;
	uint16_t TDP;
	uint16_t ConfigurableTDP;
	uint16_t TDC;
	uint16_t BatteryPowerLimit;
	uint16_t SmallPowerLimit;
	uint16_t LowCACLeakage;
	uint16_t HighCACLeakage;
	uint16_t MaximumPowerDeliveryLimit;
	uint16_t TjMax;
	uint16_t PowerTuneDataSetID;
	uint16_t EDCLimit;
	uint16_t SoftwareShutdownTemp;
	uint16_t ClockStretchAmount;
	uint16_t TemperatureLimitHotspot;
	uint16_t TemperatureLimitLiquid1;
	uint16_t TemperatureLimitLiquid2;
	uint16_t TemperatureLimitVrVddc;
	uint16_t TemperatureLimitVrMvdd;
	uint16_t TemperatureLimitPlx;
	uint8_t Liquid1_I2C_Address;
	uint8_t Liquid2_I2C_Address;
	uint8_t Liquid_I2C_Line;
	uint8_t Vr_I2C_Address;
	uint8_t Vr_I2C_Line;
	uint8_t Plx_I2C_Address;
	uint8_t Plx_I2C_Line;
	uint16_t Reserved;
} PolarisPowerTuneTable;

typedef struct _TongaPowerTuneTable
{
	uint8_t RevId;
	uint16_t TDP;
	uint16_t ConfigurableTDP;
	uint16_t TDC;
	uint16_t BatteryPowerLimit;
	uint16_t SmallPowerLimit;
	uint16_t LowCACLeakage;
	uint16_t HighCACLeakage;
	uint16_t MaximumPowerDeliveryLimit;
	uint16_t TjMax;
	uint16_t PowerTuneDataSetID;
	uint16_t EDCLimit;
	uint16_t SoftwareShutdownTemp;
	uint16_t ClockStretchAmount;
	uint16_t Reserved[2];
} TongaPowerTuneTable;

typedef struct _PolarisPPMTable
{
	uint8_t RevisionID;
	uint8_t PPMDesign;
	uint16_t CPUCoreNumber;
	uint32_t PlatformTDP;
	uint32_t SmallACPPlatformTDP;
	uint32_t PlatformTDC;
	uint32_t SmallACPPlatformTDC;
	uint32_t APUTDP;
	uint32_t DGPUTDP;
	uint32_t DGPUULVPower;
	uint32_t TjMax;
} PolarisPPMTable;

typedef struct _PolarisMemClkDepRecord
{
	uint8_t VDDC;
	uint16_t VDDCI;
	int16_t VDDCGFXOffset;
	uint16_t MVDD;
	uint32_t MemClk;
	uint16_t Reserved;
} PolarisMemClkDepRecord;

typedef struct _PolarisMemClkDepTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;

	PolarisMemClkDepRecord Entries[1];
} PolarisMemClkDepTable;

typedef struct _PolarisCoreClkDepRecord
{
	uint8_t VDDC;
	int16_t VDDCOffset;
	uint32_t CoreClk;
	uint16_t EDCCurrent;
	uint8_t ReliabilityTemperature;
	uint8_t CKSOffsetAndDisable;			// bits 0-6: volt offset, 7: enable/disable
	int32_t SClkOffset;						// Polaris only!
} PolarisCoreClkDepRecord;

typedef struct _TongaCoreClkDepRecord
{
	uint8_t VDDC;
	int16_t VDDCOffset;
	uint32_t CoreClk;
	uint16_t EDCCurrent;
	uint8_t ReliabilityTemperature;
	uint8_t CKSOffsetAndDisable;			// bits 0-6: volt offset, 7: enable/disable
} TongaCoreClkDepRecord;

typedef struct _TongaCoreClkDepTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	TongaCoreClkDepRecord Entries[1];
} TongaCoreClkDepTable;

typedef struct _PolarisCoreClkDepTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	PolarisCoreClkDepRecord Entries[1];
} PolarisCoreClkDepTable;

typedef struct _PolarisVoltageLookupRecord
{
	uint16_t VDD;
	uint16_t CACLow;
	uint16_t CACMid;
	uint16_t CACHigh;
} PolarisVoltageLookupRecord;

typedef struct _PolarisVoltageLookupTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	PolarisVoltageLookupRecord Entries[1];
} PolarisVoltageLookupTable;

typedef struct _PolarisMMDepRecord
{
	uint8_t VDDC;
	int16_t VDDCGFXOffset;	// Offset relative to VDDC
	uint32_t DClk;			// UVD D-clock
	uint32_t VClk;			// UVD V-clock
	uint32_t EClk;			// VCE clock
	uint32_t AClk;			// ACP clock?
	uint32_t SAMUClk;
} PolarisMMDepRecord;

typedef struct _PolarisMMDepTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	PolarisMMDepRecord Entries[1];
} PolarisMMDepTable;

typedef struct _PolarisVCEStateRecord
{
	uint8_t VCEClockIdx;		// References MM dep table, the VCEDependencyTableOffset value
	uint8_t Flag;				// 2 bits indicates memory p-states?
	uint8_t SCLKIdx;
	uint8_t MCLKIdx;
} PolarisVCEStateRecord;

typedef struct _PolarisVCEStateTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	PolarisVCEStateRecord Entries[1];
} PolarisVCEStateTable;

typedef struct _PolarisHardLimitRecord
{
	uint32_t CoreClkLimit;
	uint32_t MemClkLimit;
	uint16_t VDDCLimit;
	uint16_t VDDCILimit;
	uint16_t VDDGFXLimit;
} PolarisHardLimitRecord;

typedef struct _PolarisHardLimitTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	PolarisHardLimitRecord Entries[1];
} PolarisHardLimitTable;

typedef struct _PolarisState
{
	uint8_t CoreClockIdxHigh;
	uint8_t CoreClockIdxLow;
	uint8_t MemClockIdxHigh;
	uint8_t MemClockIdxLow;

	uint8_t PCIEGenLow;
	uint8_t PCIEGenHigh;
	uint8_t PCIELaneLow;
	uint8_t PCIELaneHigh;

	uint16_t Classification;
	uint32_t CapsAndSettings;
	uint16_t Classification2;
	uint8_t Unused[4];
} PolarisState;

typedef struct _PolarisStateArrayTable
{
	uint8_t RevisionID;
	uint8_t NumEntries;
	PolarisState Entries[1];
} PolarisStateArrayTable;

void GetGPUHWMonPath(char **HWMonPath, uint32_t GPUIdx);

#pragma pack(pop)

#endif
