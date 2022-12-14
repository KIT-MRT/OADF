#******************************************************************************
#**  CarMaker - Version 9.0.1
#**  Vehicle Dynamics Simulation Toolkit
#**
#**  Copyright (C)   IPG Automotive GmbH
#**                  Bannwaldallee 60             Phone  +49.721.98520.0
#**                  76185 Karlsruhe              Fax    +49.721.98520.99
#**                  Germany                      WWW    www.ipg-automotive.com
#******************************************************************************
#**
#**  Application Makefile
#**  Run with 'make V=1 ...' for a verbose build.
#**
#******************************************************************************

CMVersion = 9.1

$(info OS='$(OS)')
ifeq ($(OS),Windows_NT)
    CMPathMakeDefs = $(IPGHOME)/carmaker/win64-$(CMVersion)/include/MakeDefs.win64
else
    CMPathMakeDefs = $(IPGHOME)/carmaker/linux64-$(CMVersion)/include/MakeDefs.linux64
endif

$(info Including '$(CMPathMakeDefs)')
include $(CMPathMakeDefs)

APP_VER =		"UNICARagil Prototype with CMRosIF and Driver Trajectory extension"
APP_NAME =		CarMaker.$(ARCH)$(EXE_EXT)

OPT_CFLAGS =		-g -O1

#Use flag -DTUDa_NO_BRAINSTEM_BIG or -DTUDa_NO_BRAINSTEM_SMALL 
DEF_CFLAGS+=-DTUDa_NO_BRAINSTEM_BIG

SRC_DIR = ../ftr-core/*.cpp ../ftr-core/Lib/LowPassFilter/*.cpp ../ftr-core/Lib/ALGLIB/*.cpp ../tp-core/*.cpp																																															  
LD_LIBS =		$(CAR_LIB) $(CARMAKER_LIB) $(DRIVER_LIB) $(ROAD_LIB) $(TIRE_LIB)
#OBJS =			CM_Main.o CM_Vehicle.o User.o AllWheelSteering.o WheelControlModel.o VehicleControl_UNICAR.o

SRCS = $(wildcard  $(SRC_DIR) *.cpp)
OBJS = $(patsubst %.cpp,%.o, $(SRCS))

ifeq ($(ARCHF),win32)
    # win32/win64 -> "-lpthread" necessary
    LD_LIBS_OS += -lpthread
else
    # Xeno -> Makedefs already adds "-lrt" and "-rdynamic"
    # win32/win64 -> currently static library
    LD_LIBS_OS += -lrt -rdynamic

    # CMRosIF and current implementation of DriverTrajectory on valid
    # when running on Linux with CarMaker ROS Node
    ifneq ($(ARCH),xeno)
        # CarMaker extension CMRosIF (provided by IPG)
        DEF_CFLAGS += -DWITH_CMROSIF
        LD_LIBS_OS += -lCMRosIF-$(ARCH)

        # Driver Trajectory extension
        DEF_CFLAGS += -DWITH_DRVTRJ
        LD_LIBS_OS += -lDriverTrajectory-$(ARCH)-CM$(CARMAKER_VER)
        LDFLAGS    += -Wl,--wrap=IPGDrv_AddDrivOrder
        LDFLAGS    += -Wl,--wrap=Get_Course_TrajectoryGenerator
        LDFLAGS    += -Wl,--wrap=Get_Vel_TrajectoryGenerator_s 
    endif

endif
LDFLAGS    += -L./../lib/
LDFLAGS    += -Wl,-rpath,'$$ORIGIN/../lib/'

# Prepend local include/library directory to include path:
# PREINC_CFLAGS +=		-I../include -I../lib/$(ARCH) -I../lib

# Append local include/library directory to include path:
INC_CFLAGS +=		-I../include -I../lib/$(ARCH) -I../lib


### Linking with RTW-built Simulink models

#MATSUPP_MATVER =	R2017a
#LD_LIBS +=		$(MATSUPP_LIB)


# @@PLUGIN-BEGIN-LIBS@@ - Automatically generated code - don't edit!
# @@PLUGIN-END@@

### END (Linking with RTW-built Simulink models)

OBJS_linux += ../lib/libUNICARSteer_$(ARCH).a
OBJS_linux += ../lib/libUNICARBrake_$(ARCH).a
OBJS_linux += ../lib/libUNICARPTControl_$(ARCH).a
OBJS_linux += ../lib/libUNICARPTMotor_$(ARCH).a
OBJS_linux += ../lib/libUNICARPTMotorCU_$(ARCH).a
OBJS_linux += ../lib/libUNICARPTGearBox_$(ARCH).a
OBJS_linux += ../lib/libFTR.a
OBJS_linux += ../lib/libDCM.a

default:	clean $(APP_NAME) install_cp
$(APP_NAME):	$(OBJS_$(ARCH)) $(OBJS) $(LD_LIBS_MK) app_tmp.o
	$(QECHO) " LD     $@"
	$Q $(CXX) $(CXXFLAGS) $(CXXFAGS_CM4SL) $(LDFLAGS) -o $@ \
		$(OBJS_$(ARCH)) $(OBJS) $(OBJS_linux) -l Geographic $(LD_LIBS) $(LD_LIBS_OS) \
		app_tmp.o
	$(SET_EXE_PERMISSIONS) $@


install: $(APP_NAME)
	$(INSTALL_APP) $(APP_NAME) $(ARCH)

# Warning: Only Workaround for this example!
# - "install" creates copies with timestamp
# - here copy only for development
# - alternatively change CM executable directory
#   -> take care or relative paths for shared libraries!
# - currently no strip, ...
install_cp: $(APP_NAME)
	mkdir -p ./../bin/
	cp -f --parents $(APP_NAME) ./../bin/

clean:
	-rm -f 	*~ *% *.o core .depend $(APP_NAME) $(OBJS)

app_tmp.c: Makefile $(OBJS_$(ARCH)) $(OBJS) $(LD_LIBS_MK)
	$(QECHO) " MK     $@"
	$Q $(CREATE_INFO_CMD)

depend .depend: Makefile
	$(QECHO) " MK     $@"
#	$Q-$(CC)  $(CFLAGS)   $(DEPCFLAGS)   *.c   >  .depend 2>/dev/null
	$Q-$(CXX) $(CXXFLAGS) $(DEPCXXFLAGS) *.cpp >> .depend 2>/dev/null
include .depend
