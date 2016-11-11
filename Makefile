#############################################################################
# Makefile for building: GuardCoopSys
# Generated by qmake (3.0) (Qt 5.7.0)
# Project:  GuardCoopSys.pro
# Template: app
# Command: "D:\Program Files\Qt\5.7\msvc2015_64\bin\qmake.exe" -o Makefile GuardCoopSys.pro
#############################################################################

MAKEFILE      = Makefile

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = "D:\Program Files\Qt\5.7\msvc2015_64\bin\qmake.exe"
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		release \
		debug


release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: GuardCoopSys.pro "..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\win32-msvc2010\qmake.conf" "..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\spec_pre.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\common\angle.conf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\common\msvc-base.conf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\common\msvc-desktop.conf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\qconfig.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dcore.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dcore_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dextras.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dextras_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dinput.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dinput_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dlogic.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dlogic_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquick.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquick_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickextras.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickextras_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickinput.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickinput_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickrender.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickrender_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3drender.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3drender_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axbase.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axbase_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axcontainer.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axcontainer_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axserver.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axserver_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_bluetooth.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_bluetooth_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_bootstrap_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_clucene_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_concurrent.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_concurrent_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_core.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_core_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_dbus.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_dbus_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_designer.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_designer_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_designercomponents_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_gamepad.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_gamepad_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_gui.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_gui_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_help.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_help_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_location.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_location_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_multimedia.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_multimedia_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_multimediawidgets.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_network.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_network_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_nfc.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_nfc_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_opengl.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_opengl_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_openglextensions.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_openglextensions_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_packetprotocol_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_platformsupport_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_positioning.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_positioning_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_printsupport.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_printsupport_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_purchasing.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_purchasing_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qml.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qml_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qmldebug_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qmldevtools_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qmltest.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qmltest_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quick.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quick_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickcontrols2.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickcontrols2_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickparticles_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quicktemplates2_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickwidgets.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickwidgets_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_script.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_script_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_scripttools.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_scripttools_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_scxml.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_scxml_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_sensors.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_sensors_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_serialbus.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_serialbus_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_serialport.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_serialport_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_sql.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_sql_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_svg.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_svg_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_testlib.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_testlib_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_uiplugin.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_uitools.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_uitools_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webchannel.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webchannel_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webengine.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webengine_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginecore.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginecore_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginewidgets.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_websockets.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_websockets_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webview.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webview_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_widgets.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_widgets_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_winextras.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_winextras_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_xml.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_xml_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_xmlpatterns.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_zlib_private.pri" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\qt_functions.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\qt_config.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\qt_config.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\win32-msvc2010\qmake.conf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\spec_post.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\exclusive_builds.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\default_pre.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\default_pre.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\resolve_config.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\exclusive_builds_post.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\default_post.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\rtti.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\precompile_header.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\warn_on.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\qt.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\resources.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\moc.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\opengl.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\uic.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\file_copies.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\windows.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\testcase_targets.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\exceptions.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\yacc.prf" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\lex.prf" \
		GuardCoopSys.pro \
		"..\..\Program Files\Qt\5.7\msvc2015_64\lib\qtmain.prl" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\lib\Qt5Widgets.prl" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\lib\Qt5Gui.prl" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\lib\Qt5Sql.prl" \
		"..\..\Program Files\Qt\5.7\msvc2015_64\lib\Qt5Core.prl"
	$(QMAKE) -o Makefile GuardCoopSys.pro
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\spec_pre.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\common\angle.conf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\common\msvc-base.conf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\common\msvc-desktop.conf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\qconfig.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dcore.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dcore_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dextras.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dextras_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dinput.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dinput_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dlogic.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dlogic_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquick.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquick_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickextras.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickextras_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickinput.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickinput_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickrender.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3dquickrender_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3drender.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_3drender_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axbase.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axbase_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axcontainer.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axcontainer_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axserver.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_axserver_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_bluetooth.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_bluetooth_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_bootstrap_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_clucene_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_concurrent.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_concurrent_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_core.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_core_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_dbus.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_dbus_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_designer.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_designer_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_designercomponents_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_gamepad.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_gamepad_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_gui.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_gui_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_help.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_help_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_location.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_location_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_multimedia.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_multimedia_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_multimediawidgets.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_network.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_network_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_nfc.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_nfc_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_opengl.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_opengl_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_openglextensions.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_openglextensions_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_packetprotocol_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_platformsupport_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_positioning.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_positioning_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_printsupport.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_printsupport_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_purchasing.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_purchasing_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qml.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qml_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qmldebug_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qmldevtools_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qmltest.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qmltest_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quick.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quick_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickcontrols2.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickcontrols2_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickparticles_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quicktemplates2_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickwidgets.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_quickwidgets_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_script.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_script_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_scripttools.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_scripttools_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_scxml.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_scxml_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_sensors.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_sensors_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_serialbus.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_serialbus_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_serialport.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_serialport_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_sql.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_sql_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_svg.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_svg_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_testlib.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_testlib_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_uiplugin.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_uitools.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_uitools_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webchannel.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webchannel_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webengine.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webengine_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginecore.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginecore_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginewidgets.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_websockets.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_websockets_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webview.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_webview_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_widgets.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_widgets_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_winextras.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_winextras_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_xml.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_xml_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_xmlpatterns.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\modules\qt_lib_zlib_private.pri":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\qt_functions.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\qt_config.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\qt_config.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\win32-msvc2010\qmake.conf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\spec_post.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\exclusive_builds.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\default_pre.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\default_pre.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\resolve_config.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\exclusive_builds_post.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\default_post.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\rtti.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\precompile_header.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\warn_on.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\qt.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\resources.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\moc.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\opengl.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\uic.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\file_copies.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\win32\windows.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\testcase_targets.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\exceptions.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\yacc.prf":
"..\..\Program Files\Qt\5.7\msvc2015_64\mkspecs\features\lex.prf":
GuardCoopSys.pro:
"..\..\Program Files\Qt\5.7\msvc2015_64\lib\qtmain.prl":
"..\..\Program Files\Qt\5.7\msvc2015_64\lib\Qt5Widgets.prl":
"..\..\Program Files\Qt\5.7\msvc2015_64\lib\Qt5Gui.prl":
"..\..\Program Files\Qt\5.7\msvc2015_64\lib\Qt5Sql.prl":
"..\..\Program Files\Qt\5.7\msvc2015_64\lib\Qt5Core.prl":
qmake: FORCE
	@$(QMAKE) -o Makefile GuardCoopSys.pro

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
	-$(DEL_FILE) GuardCoopSys.exp
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) GuardCoopSys.lib

release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
