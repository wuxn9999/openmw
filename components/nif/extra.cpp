#include "extra.hpp"

namespace Nif
{

    void NiExtraData::read(NIFStream* nif)
    {
        Extra::read(nif);

        nif->readVector(mData, mRecordSize);
    }

    void NiStringsExtraData::read(NIFStream* nif)
    {
        Extra::read(nif);

        nif->getSizedStrings(mData, nif->get<uint32_t>());
    }

    void NiTextKeyExtraData::read(NIFStream* nif)
    {
        Extra::read(nif);

        uint32_t numKeys;
        nif->read(numKeys);
        mList.resize(numKeys);
        for (TextKey& key : mList)
        {
            nif->read(key.mTime);
            nif->read(key.mText);
        }
    }

    void NiVertWeightsExtraData::read(NIFStream* nif)
    {
        Extra::read(nif);

        nif->skip(nif->get<uint16_t>() * sizeof(float)); // vertex weights I guess
    }

    void BSBound::read(NIFStream* nif)
    {
        Extra::read(nif);

        nif->read(mCenter);
        nif->read(mExtents);
    }

    void BSFurnitureMarker::LegacyFurniturePosition::read(NIFStream* nif)
    {
        nif->read(mOffset);
        nif->read(mOrientation);
        nif->read(mPositionRef);
        nif->skip(1); // Position ref 2
    }

    void BSFurnitureMarker::FurniturePosition::read(NIFStream* nif)
    {
        nif->read(mOffset);
        nif->read(mHeading);
        nif->read(mType);
        nif->read(mEntryPoint);
    }

    void BSFurnitureMarker::read(NIFStream* nif)
    {
        Extra::read(nif);

        uint32_t num;
        nif->read(num);
        if (nif->getBethVersion() <= NIFFile::BethVersion::BETHVER_FO3)
        {
            mLegacyMarkers.resize(num);
            for (auto& marker : mLegacyMarkers)
                marker.read(nif);
        }
        else
        {
            mMarkers.resize(num);
            for (auto& marker : mMarkers)
                marker.read(nif);
        }
    }

    void BSInvMarker::read(NIFStream* nif)
    {
        Extra::read(nif);

        float rotX = nif->get<uint16_t>() / 1000.f;
        float rotY = nif->get<uint16_t>() / 1000.f;
        float rotZ = nif->get<uint16_t>() / 1000.f;
        mRotation = osg::Quat(rotX, osg::X_AXIS, rotY, osg::Y_AXIS, rotZ, osg::Z_AXIS);
        nif->read(mScale);
    }

    void BSBehaviorGraphExtraData::read(NIFStream* nif)
    {
        Extra::read(nif);

        nif->read(mFile);
        nif->read(mControlsBaseSkeleton);
    }

    void BSBoneLODExtraData::read(NIFStream* nif)
    {
        Extra::read(nif);

        mData.resize(nif->get<uint32_t>());
        for (BoneLOD& lod : mData)
            lod.read(nif);
    }

    void BSBoneLODExtraData::BoneLOD::read(NIFStream* nif)
    {
        nif->read(mDistance);
        nif->read(mBone);
    }

    void BSDecalPlacementVectorExtraData::read(NIFStream* nif)
    {
        NiFloatExtraData::read(nif);

        mBlocks.resize(nif->get<uint16_t>());
        for (Block& block : mBlocks)
            block.read(nif);
    }

    void BSDecalPlacementVectorExtraData::Block::read(NIFStream* nif)
    {
        nif->readVector(mPoints, nif->get<uint16_t>());
        nif->readVector(mNormals, mPoints.size());
    }

    void BSClothExtraData::read(NIFStream* nif)
    {
        nif->readVector(mData, nif->get<uint32_t>());
    }

}
