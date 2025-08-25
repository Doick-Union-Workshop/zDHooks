namespace GOTHIC_NAMESPACE
{
    int zVob_GetFloorPosition(zCVob* t_vob, zVEC3& t_pos)
    {
        zCWorld* wld = t_vob->GetHomeWorld();

        if (!wld) return 0;

        zREAL diff = t_vob->GetPositionWorld()[VY] - t_vob->bbox3D.mins[VY];

        if (wld->TraceRayNearestHit(t_pos, zVEC3(0, -1000, 0), t_vob, zTRACERAY_STAT_POLY | zTRACERAY_VOB_IGNORE_NO_CD_DYN))
        {
            if (wld->traceRayReport.foundPoly || wld->traceRayReport.foundVob)
            {
                zVEC3 newpos = wld->traceRayReport.foundIntersection;
                newpos[VY] += diff + 4;
                t_pos = newpos;
                return 1;
            }
        }

        return 0;
    }

    void zVob_SetOnFloor(zCVob* t_vob, zVEC3& t_pos)
    {
        static Utils::Logger* log = Utils::CreateLogger("zDExternals::zCVob::SetOnFloor");

        if (!zVob_GetFloorPosition(t_vob, t_pos))
        {
            zSTRING vobName = t_vob->GetObjectName();
            log->Error("Cannot set to floor Vob with specified name: {0}", vobName.Upper().ToChar());
            return;
        }

        t_vob->SetPositionWorld(t_pos);
    }

    static void Vob_Rotate(const zSTRING& t_vobName, C_POSITION* t_vobPosition)
    {
        if (t_vobName.IsEmpty() || !t_vobPosition)
            return;

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Vob_Rotate");

        zSTRING vobName = zSTRING(t_vobName).Upper();
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);

        if (!vob)
        {
            log->Error("No Vob found with specified name: {0}", vobName.ToChar());
            return;
        }

        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->collDetectionStatic = 0;
        vob->collDetectionDynamic = 0;

        vob->RotateWorldX((float)t_vobPosition->X);
        vob->RotateWorldY((float)t_vobPosition->Y);
        vob->RotateWorldZ((float)t_vobPosition->Z);

        vob->collDetectionStatic = collDetectionStatic;
        vob->collDetectionDynamic = collDetectionDynamic;
    }

    static void Vob_SetVisual(const zSTRING& t_vobName, const zSTRING& t_visualName)
    {
        if (t_vobName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Vob_SetVisual");

        zSTRING vobName = zSTRING(t_vobName).Upper();
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);

        if (!vob)
        {
            log->Error("No Vob found with specified name: {0}", vobName.ToChar());
            return;
        }

        zSTRING visualName = t_visualName;
        visualName.Upper();
        vob->SetVisual(zCVisual::LoadVisual(visualName));
    }

    static void Vob_SetToFloor(const zSTRING& t_vobName)
    {
        if (t_vobName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Vob_SetToFloor");

        zSTRING vobName = zSTRING(t_vobName).Upper();
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);

        if (!vob)
        {
            log->Error("No Vob found with specified name: {0}", vobName.ToChar());
            return;
        }

        zVEC3 pos = vob->GetPositionWorld();
        zVob_SetOnFloor(vob, pos);
    }

    static void Vob_MoveTo(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        if (t_vobName.IsEmpty() || t_pointName.IsEmpty())
            return;

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Vob_MoveTo");

        zSTRING vobName = zSTRING(t_vobName).Upper();
        oCWorld* world = ogame->GetGameWorld();
        zCVob* vob = world->SearchVobByName(vobName);

        if (!vob)
        {
            log->Warning("No Vob found with specified name: {0}", vobName.ToChar());
            return;
        }

        zSTRING pointName = zSTRING(t_pointName).Upper();
        zCWaypoint* wp = world->wayNet->GetWaypoint(pointName);
        zVEC3 pos;

        if (wp) {
            pos = wp->GetPositionWorld();
        }
        else
        {
            zCVob* pointVob = world->SearchVobByName(pointName);
            if (!pointVob) return;
            pos = pointVob->GetPositionWorld();
        }

        SetPositionWorld(vob, pos);
    }

    static void Vob_MoveToPos(const zSTRING& t_vobName, C_POSITION* t_vobPosition)
    {
        if (t_vobName.IsEmpty() || !t_vobPosition) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Vob_MoveToPos");

        zSTRING vobName = zSTRING(t_vobName).Upper();
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);

        if (!vob)
        {
            log->Warning("No Vob found with specified name: {0}", vobName.ToChar());
            return;
        }

        zVEC3 pos = zVEC3(t_vobPosition->X, t_vobPosition->Y, t_vobPosition->Z);
        SetPositionWorld(vob, pos);
    }

    static void Vob_SetCollisionDetection(const zSTRING& t_vobName, const int dynamicCollDet, const int staticCollDet)
    {
        if (t_vobName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Vob_SetCollisionDetection");

        zSTRING vobName = zSTRING(t_vobName).Upper();
        zCVob* vob = ogame->GetGameWorld()->SearchVobByName(vobName);

        if (!vob)
        {
            log->Warning("No Vob found with specified name: {0}", vobName.ToChar());
            return;
        }

        vob->collDetectionDynamic = dynamicCollDet;
        vob->collDetectionStatic = staticCollDet;
    }
}