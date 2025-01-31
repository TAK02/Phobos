#pragma once
#include <TerrainTypeClass.h>

#include <Helpers/Macro.h>
#include "../_Container.hpp"
#include "../../Utilities/TemplateDef.h"

class TerrainTypeExt
{
public:
    using base_type = TerrainTypeClass;

    class ExtData final : public Extension<TerrainTypeClass>
    {
    public:
        Valueable<int> SpawnsTiberium_Type;
        Valueable<int> SpawnsTiberium_Range;

        ExtData(TerrainTypeClass* OwnerObject) : Extension<TerrainTypeClass>(OwnerObject),
            SpawnsTiberium_Type(0),
            SpawnsTiberium_Range(1)
        { }

        virtual ~ExtData() = default;

        virtual void LoadFromINIFile(CCINIClass* pINI) override;

        virtual void InvalidatePointer(void* ptr, bool bRemoved) override {}

        virtual void LoadFromStream(PhobosStreamReader& Stm) override;
        virtual void SaveToStream(PhobosStreamWriter& Stm) override;
    
    private:
        template <typename T>
        void Serialize(T& Stm);
    };

    class ExtContainer final : public Container<TerrainTypeExt> {
    public:
        ExtContainer();
        ~ExtContainer();
    };

    static ExtContainer ExtMap;

    static bool LoadGlobals(PhobosStreamReader& Stm);
    static bool SaveGlobals(PhobosStreamWriter& Stm);
};