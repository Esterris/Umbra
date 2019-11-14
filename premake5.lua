workspace "Umbra"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Umbra"
	location "Umbra"
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
		"Umbra/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UM_PLATFORM_WINDOWS",
			"UM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "UM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UM_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "UM_DIST"
		symbols "On"

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
		"Umbra/vendor/spdlog/include",
		"Umbra/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UM_PLATFORM_WINDOWS"
		}

		links
		{
			"Umbra"
		}

	filter "configurations:Debug"
		defines "UM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UM_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "UM_DIST"
		symbols "On"