#
# Copyright (C) 2013 The Android Open-Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

ifdef TW_DEVICE_SPECIFIC_VERSION
	TWRP_VERSION := $(TW_DEVICE_SPECIFIC_VERSION)
else
	TWRP_VERSION := $(shell cat bootable/recovery/variables.h | grep TW_VERSION_STR | cut -d\" -f2)
endif

ifeq ($(TARGET_RECOVERY_IS_MULTIROM),true)
	TWRP_NAME := twrpm-$(TWRP_VERSION)-$(TARGET_DEVICE)
else
	TWRP_NAME := twrp-$(TWRP_VERSION)-$(TARGET_DEVICE)
endif

INTERNAL_MTK_RECOVERYIMAGE_ARGS := \
		--kernel $(recovery_kernel) \
		--ramdisk $(recovery_ramdisk) \
		--mtk recovery

$(INSTALLED_RECOVERYIMAGE_TARGET): $(MKBOOTIMG) \
	$(recovery_ramdisk) $(recovery_kernel)
	@echo -e ${CL_CYN}"----- Making recovery image ------"${CL_RST}
	$(MKBOOTIMG) $(INTERNAL_MTK_RECOVERYIMAGE_ARGS) \
	$(BOARD_MKBOOTIMG_ARGS) --output $@
	$(hide) $(call assert-max-image-size,$@, \
	$(BOARD_RECOVERYIMAGE_PARTITION_SIZE),raw)
	cd $(PRODUCT_OUT) && cp recovery.img $(TWRP_NAME).img
	@echo -e ${PRT_IMG}"----- Made recovery image: $(PRODUCT_OUT)/$(TWRP_NAME).img --------"${CL_RST}
