#ifndef OPENMW_COMPONENTS_SETTINGS_CATEGORIES_SOUND_H
#define OPENMW_COMPONENTS_SETTINGS_CATEGORIES_SOUND_H

#include "components/settings/sanitizerimpl.hpp"
#include "components/settings/settingvalue.hpp"

#include <osg/Math>
#include <osg/Vec2f>
#include <osg/Vec3f>

#include <cstdint>
#include <string>
#include <string_view>

namespace Settings
{
    struct SoundCategory : WithIndex
    {
        using WithIndex::WithIndex;

        SettingValue<std::string> mDevice{ mIndex, "Sound", "device" };
        SettingValue<float> mMasterVolume{ mIndex, "Sound", "master volume", makeClampSanitizerFloat(0, 1) };
        SettingValue<float> mFootstepsVolume{ mIndex, "Sound", "footsteps volume", makeClampSanitizerFloat(0, 1) };
        SettingValue<float> mMusicVolume{ mIndex, "Sound", "music volume", makeClampSanitizerFloat(0, 1) };
        SettingValue<float> mSfxVolume{ mIndex, "Sound", "sfx volume", makeClampSanitizerFloat(0, 1) };
        SettingValue<float> mVoiceVolume{ mIndex, "Sound", "voice volume", makeClampSanitizerFloat(0, 1) };
        SettingValue<int> mBufferCacheMin{ mIndex, "Sound", "buffer cache min", makeMaxSanitizerInt(1) };
        SettingValue<int> mBufferCacheMax{ mIndex, "Sound", "buffer cache max", makeMaxSanitizerInt(1) };
        SettingValue<int> mHrtfEnable{ mIndex, "Sound", "hrtf enable", makeEnumSanitizerInt({ -1, 0, 1 }) };
        SettingValue<std::string> mHrtf{ mIndex, "Sound", "hrtf" };
    };
}

#endif
