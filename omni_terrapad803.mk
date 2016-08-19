$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Time Zone
PRODUCT_COPY_FILES += \
	bionic/libc/zoneinfo/tzdata:recovery/root/system/usr/share/zoneinfo/tzdata

#PRODUCT_BUILD_PROP_OVERRIDES += \
#    PRODUCT_MODEL="terra803" \
#    TARGET_DEVICE="terra803"

PRODUCT_NAME := omni_terrapad803
PRODUCT_DEVICE := terrapad803
PRODUCT_BRAND := Terra
PRODUCT_MANUFACTURER := Terra
PRODUCT_MODEL := Terrapad 803
