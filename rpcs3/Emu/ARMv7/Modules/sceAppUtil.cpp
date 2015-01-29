#include "stdafx.h"
#include "Emu/System.h"
#include "Emu/ARMv7/PSVFuncList.h"

extern psv_log_base sceAppUtil;

struct SceAppUtilInitParam
{
	u32 workBufSize;
	char reserved[60];
};

struct SceAppUtilBootParam
{
	u32 attr;
	u32 appVersion;
	char reserved[32];
};

struct SceAppUtilSaveDataMountPoint
{
	char data[16];
};

struct SceAppUtilSaveDataSlotParam
{
	u32 status;
	char title[64];
	char subTitle[128];
	char detail[512];
	char iconPath[64];
	s32 userParam;
	u32 sizeKB;
	SceDateTime modifiedTime;
	char reserved[48];
};

struct SceAppUtilSaveDataSlotEmptyParam
{
	vm::psv::ptr<char> title;
	vm::psv::ptr<char> iconPath;
	vm::psv::ptr<void> iconBuf;
	u32 iconBufSize;
	char reserved[32];
};

struct SceAppUtilSaveDataSlot
{
	u32 id;
	u32 status;
	s32 userParam;
	vm::psv::ptr<SceAppUtilSaveDataSlotEmptyParam> emptyParam;
};

struct SceAppUtilSaveDataFile
{
	vm::psv::ptr<const char> filePath;
	vm::psv::ptr<void> buf;
	u32 bufSize;
	s64 offset;
	u32 mode;
	u32 progDelta;
	char reserved[32];
};

struct SceAppUtilSaveDataFileSlot
{
	u32 id;
	vm::psv::ptr<SceAppUtilSaveDataSlotParam> slotParam;
	char reserved[32];
};

s32 sceAppUtilInit(vm::psv::ptr<const SceAppUtilInitParam> initParam, vm::psv::ptr<SceAppUtilBootParam> bootParam)
{
	throw __FUNCTION__;
}

s32 sceAppUtilShutdown()
{
	throw __FUNCTION__;
}

s32 sceAppUtilSaveDataSlotCreate(u32 slotId, vm::psv::ptr<const SceAppUtilSaveDataSlotParam> param, vm::psv::ptr<const SceAppUtilSaveDataMountPoint> mountPoint)
{
	throw __FUNCTION__;
}

s32 sceAppUtilSaveDataSlotDelete(u32 slotId, vm::psv::ptr<const SceAppUtilSaveDataMountPoint> mountPoint)
{
	throw __FUNCTION__;
}

s32 sceAppUtilSaveDataSlotSetParam(u32 slotId, vm::psv::ptr<const SceAppUtilSaveDataSlotParam> param, vm::psv::ptr<const SceAppUtilSaveDataMountPoint> mountPoint)
{
	throw __FUNCTION__;
}

s32 sceAppUtilSaveDataSlotGetParam(u32 slotId, vm::psv::ptr<SceAppUtilSaveDataSlotParam> param, vm::psv::ptr<const SceAppUtilSaveDataMountPoint> mountPoint)
{
	throw __FUNCTION__;
}

s32 sceAppUtilSaveDataFileSave(vm::psv::ptr<const SceAppUtilSaveDataFileSlot> slot, vm::psv::ptr<const SceAppUtilSaveDataFile> files, u32 fileNum, vm::psv::ptr<const SceAppUtilSaveDataMountPoint> mountPoint, vm::psv::ptr<u32> requiredSizeKB)
{
	throw __FUNCTION__;
}

s32 sceAppUtilPhotoMount()
{
	throw __FUNCTION__;
}

s32 sceAppUtilPhotoUmount()
{
	throw __FUNCTION__;
}

s32 sceAppUtilSystemParamGetInt(u32 paramId, vm::psv::ptr<s32> value)
{
	throw __FUNCTION__;
}

s32 sceAppUtilSystemParamGetString(u32 paramId, vm::psv::ptr<char> buf, u32 bufSize)
{
	throw __FUNCTION__;
}

s32 sceAppUtilSaveSafeMemory(vm::psv::ptr<const void> buf, u32 bufSize, s64 offset)
{
	throw __FUNCTION__;
}

s32 sceAppUtilLoadSafeMemory(vm::psv::ptr<void> buf, u32 bufSize, s64 offset)
{
	throw __FUNCTION__;
}


#define REG_FUNC(nid, name) reg_psv_func(nid, &sceAppUtil, #name, name)

psv_log_base sceAppUtil("SceAppUtil", []()
{
	sceAppUtil.on_load = nullptr;
	sceAppUtil.on_unload = nullptr;
	sceAppUtil.on_stop = nullptr;

	REG_FUNC(0xDAFFE671, sceAppUtilInit);
	REG_FUNC(0xB220B00B, sceAppUtilShutdown);
	REG_FUNC(0x7E8FE96A, sceAppUtilSaveDataSlotCreate);
	REG_FUNC(0x266A7646, sceAppUtilSaveDataSlotDelete);
	REG_FUNC(0x98630136, sceAppUtilSaveDataSlotSetParam);
	REG_FUNC(0x93F0D89F, sceAppUtilSaveDataSlotGetParam);
	REG_FUNC(0x1E2A6158, sceAppUtilSaveDataFileSave);
	REG_FUNC(0xEE85804D, sceAppUtilPhotoMount);
	REG_FUNC(0x9651B941, sceAppUtilPhotoUmount);
	REG_FUNC(0x5DFB9CA0, sceAppUtilSystemParamGetInt);
	REG_FUNC(0x6E6AA267, sceAppUtilSystemParamGetString);
	REG_FUNC(0x9D8AC677, sceAppUtilSaveSafeMemory);
	REG_FUNC(0x3424D772, sceAppUtilLoadSafeMemory);
});
