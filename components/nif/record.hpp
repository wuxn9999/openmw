/*
  OpenMW - The completely unofficial reimplementation of Morrowind
  Copyright (C) 2008-2010  Nicolay Korslund
  Email: < korslund@gmail.com >
  WWW: https://openmw.org/

  This file (record.h) is part of the OpenMW package.

  OpenMW is distributed as free software: you can redistribute it
  and/or modify it under the terms of the GNU General Public License
  version 3, as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  version 3 along with this program. If not, see
  https://www.gnu.org/licenses/ .

 */

#ifndef OPENMW_COMPONENTS_NIF_RECORD_HPP
#define OPENMW_COMPONENTS_NIF_RECORD_HPP

#include <string>

namespace Nif
{

    class Reader;
    class NIFStream;

    enum RecordType
    {
        RC_MISSING = 0,
        RC_AvoidNode,
        RC_bhkBlendCollisionObject,
        RC_bhkBlendController,
        RC_bhkBoxShape,
        RC_bhkCapsuleShape,
        RC_bhkCylinderShape,
        RC_bhkCollisionObject,
        RC_bhkCompressedMeshShape,
        RC_bhkCompressedMeshShapeData,
        RC_bhkConvexListShape,
        RC_bhkConvexSweepShape,
        RC_bhkConvexTransformShape,
        RC_bhkConvexVerticesShape,
        RC_bhkHingeConstraint,
        RC_bhkLimitedHingeConstraint,
        RC_bhkListShape,
        RC_bhkMoppBvTreeShape,
        RC_bhkNiTriStripsShape,
        RC_bhkPackedNiTriStripsShape,
        RC_bhkPhysicsSystem,
        RC_bhkRagdollConstraint,
        RC_bhkRagdollSystem,
        RC_bhkRigidBody,
        RC_bhkRigidBodyT,
        RC_bhkSimpleShapePhantom,
        RC_bhkSphereShape,
        RC_BSBehaviorGraphExtraData,
        RC_BSBound,
        RC_BSBoneLODExtraData,
        RC_BSClothExtraData,
        RC_BSDecalPlacementVectorExtraData,
        RC_BSDistantTreeShaderProperty,
        RC_BSDynamicTriShape,
        RC_BSDismemberSkinInstance,
        RC_BSDistantObjectExtraData,
        RC_BSDistantObjectLargeRefExtraData,
        RC_BSEffectShaderProperty,
        RC_BSEffectShaderPropertyColorController,
        RC_BSEffectShaderPropertyFloatController,
        RC_BSExtraData,
        RC_BSFrustumFOVController,
        RC_BSFurnitureMarker,
        RC_BSInvMarker,
        RC_BSKeyframeController,
        RC_BSLagBoneController,
        RC_BSLightingShaderProperty,
        RC_BSLightingShaderPropertyColorController,
        RC_BSLightingShaderPropertyFloatController,
        RC_BSLODTriShape,
        RC_BSMaterialEmittanceMultController,
        RC_BSMeshLODTriShape,
        RC_BSMultiBound,
        RC_BSMultiBoundAABB,
        RC_BSMultiBoundOBB,
        RC_BSMultiBoundSphere,
        RC_BSNiAlphaPropertyTestRefController,
        RC_BSPackedAdditionalGeometryData,
        RC_BSRefractionFirePeriodController,
        RC_BSRefractionStrengthController,
        RC_BSShaderNoLightingProperty,
        RC_BSShaderPPLightingProperty,
        RC_BSShaderProperty,
        RC_BSShaderTextureSet,
        RC_BSTriShape,
        RC_BSWArray,
        RC_BSXFlags,
        RC_DistantLODShaderProperty,
        RC_HairShaderProperty,
        RC_hkPackedNiTriStripsData,
        RC_NiAdditionalGeometryData,
        RC_NiAlphaAccumulator,
        RC_NiAlphaController,
        RC_NiAlphaProperty,
        RC_NiBillboardNode,
        RC_NiBinaryExtraData,
        RC_NiBlendBoolInterpolator,
        RC_NiBlendFloatInterpolator,
        RC_NiBlendPoint3Interpolator,
        RC_NiBlendTransformInterpolator,
        RC_NiBoolData,
        RC_NiBooleanExtraData,
        RC_NiBoolInterpolator,
        RC_NiBoolTimelineInterpolator,
        RC_NiBSAnimationNode,
        RC_NiBSPArrayController,
        RC_NiBSParticleNode,
        RC_NiCamera,
        RC_NiClusterAccumulator,
        RC_NiCollisionObject,
        RC_NiCollisionSwitch,
        RC_NiColorData,
        RC_NiColorExtraData,
        RC_NiColorInterpolator,
        RC_NiControllerManager,
        RC_NiControllerSequence,
        RC_NiDefaultAVObjectPalette,
        RC_NiDitherProperty,
        RC_NiExtraData,
        RC_NiFlipController,
        RC_NiFloatData,
        RC_NiFloatExtraData,
        RC_NiFloatInterpolator,
        RC_NiFloatsExtraData,
        RC_NiFltAnimationNode,
        RC_NiFogProperty,
        RC_NiGeomMorpherController,
        RC_NiGravity,
        RC_NiIntegerExtraData,
        RC_NiIntegersExtraData,
        RC_NiKeyframeController,
        RC_NiKeyframeData,
        RC_NiLight,
        RC_NiLightDimmerController,
        RC_NiLines,
        RC_NiLinesData,
        RC_NiLODNode,
        RC_NiLookAtController,
        RC_NiMaterialColorController,
        RC_NiMaterialProperty,
        RC_NiMorphData,
        RC_NiMultiTargetTransformController,
        RC_NiNode,
        RC_NiPalette,
        RC_NiParticleColorModifier,
        RC_NiParticleGrowFade,
        RC_NiParticleRotation,
        RC_NiParticles,
        RC_NiParticlesData,
        RC_NiParticleSystemController,
        RC_NiPathController,
        RC_NiPixelData,
        RC_NiPlanarCollider,
        RC_NiPoint3Interpolator,
        RC_NiPosData,
        RC_NiRollController,
        RC_NiSequence,
        RC_NiSequenceStreamHelper,
        RC_NiShadeProperty,
        RC_NiSkinData,
        RC_NiSkinInstance,
        RC_NiSkinPartition,
        RC_NiSortAdjustNode,
        RC_NiSourceTexture,
        RC_NiSpecularProperty,
        RC_NiSphericalCollider,
        RC_NiStencilProperty,
        RC_NiStringExtraData,
        RC_NiStringsExtraData,
        RC_NiStringPalette,
        RC_NiSwitchNode,
        RC_NiTextKeyExtraData,
        RC_NiTextureEffect,
        RC_NiTextureTransformController,
        RC_NiTexturingProperty,
        RC_NiTransformInterpolator,
        RC_NiTriShape,
        RC_NiTriShapeData,
        RC_NiTriStrips,
        RC_NiTriStripsData,
        RC_NiUVController,
        RC_NiUVData,
        RC_NiVectorExtraData,
        RC_NiVertexColorProperty,
        RC_NiVertWeightsExtraData,
        RC_NiVisController,
        RC_NiVisData,
        RC_NiWireframeProperty,
        RC_NiZBufferProperty,
        RC_RootCollisionNode,
        RC_SkyShaderProperty,
        RC_TallGrassShaderProperty,
        RC_TileShaderProperty,
        RC_VolumetricFogShaderProperty,
        RC_WaterShaderProperty,
    };

    /// Base class for all records
    struct Record
    {
        // Record type and type name
        RecordType recType{ RC_MISSING };
        std::string recName;
        unsigned int recIndex{ ~0u };

        Record() = default;

        /// Parses the record from file
        virtual void read(NIFStream* nif) = 0;

        /// Does post-processing, after the entire tree is loaded
        virtual void post(Reader& nif) {}

        virtual ~Record() {}
    };

} // Namespace
#endif
