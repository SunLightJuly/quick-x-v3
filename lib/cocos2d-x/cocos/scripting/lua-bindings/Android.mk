LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE    := cocos_lua_static

LOCAL_MODULE_FILENAME := liblua

LOCAL_SRC_FILES := $(APP_ANDROID_PREBUILD)/$(APP_ABI)/liblua.a


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../external/lua/tolua \
                           $(LOCAL_PATH)/../../../external/lua/luajit/include \
                           $(LOCAL_PATH)/../external \
                           $(LOCAL_PATH)/auto \
                           $(LOCAL_PATH)/manual


LOCAL_WHOLE_STATIC_LIBRARIES := luajit_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += websockets_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
#LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
#LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
#LOCAL_WHOLE_STATIC_LIBRARIES += spine_static

LOCAL_CFLAGS += -Wno-psabi
LOCAL_EXPORT_CFLAGS += -Wno-psabi

include $(PREBUILT_STATIC_LIBRARY)

$(call import-module,lua/luajit/prebuilt/android)
$(call import-module,extensions)
$(call import-module,.)
$(call import-module,websockets/prebuilt/android)
$(call import-module,network)
#$(call import-module,editor-support/cocostudio)
#$(call import-module,editor-support/cocosbuilder)
#$(call import-module,editor-support/spine)
