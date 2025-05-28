workspace "NudeEngine"

    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }



outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



project "NudeEngine"

    location "NudeEngine"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NU_PLATFORM_WINDOWS",
            "NU_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        buildoptions "/utf-8"
    
    filter "configurations:Debug"
        defines "NU_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "NU_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "NU_DIST"
        optimize "On"
        


project "Sandbox"

    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "NudeEngine/vendor/spdlog/include",
        "NudeEngine/src"
    }

    links
    {
        "NudeEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NU_PLATFORM_WINDOWS"
        }

        buildoptions "/utf-8"
    
    filter "configurations:Debug"
        defines "NU_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "NU_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "NU_DIST"
        optimize "On"