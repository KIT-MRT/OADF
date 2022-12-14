#*****************************************************-*- Mode: Makefile -*- **#
#*  Model-specific Makefile                                                   *#
#*  ------------------------------------------------------------------------  *#
#*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  *#
#*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 *#
#******************************************************************************#


# ------------------------------------------------------------------------------
# User defined settings:
# ------------------------------------------------------------------------------

include C:/IPG/carmaker/win64-9.1/include/MakeDefs.win64

# Matlab version in use.
MATSUPP_MATVER  = R2019b
MATSUPP_NUMVER  = 90700


# ------------------------------------------------------------------------------
# No user defined settings below this line!
# ------------------------------------------------------------------------------

# The following macros are read by the Real-Time Workshop build procedure:
MATLAB_ROOT	= $(subst \,/,C:\Program Files\MATLAB\R2019b)
ALT_MATLAB_ROOT	= $(subst \,/,C:\PROGRA~1\MATLAB\R2019b)
MAKECMD         = "C:/IPG/carmaker/win64-9.1/bin/cmmake"
HOST            = ANY
BUILD           = yes
SYS_TARGET_FILE = CarMaker.tlc

# In the case when Plugin Model is generated for CarMaker/HIL dSPACE
ifneq ($(DSPACE_ROOT),)
DSMAKECMD = "$(DSPACE_ROOT)/Exe/dsmake"
else
DSMAKECMD = dsmake
endif

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif


MODEL		= UNICARPTMotor
WRAPPER		= UNICARPTMotor_wrap
CLASS		= PTMotor
DESCRIPTION	= "UNICARPTMotor"
MAINMODEL	= ""
PARAMID		= 1
SYMBOLS		= ""

MODELREFS                 = ""
MODELLIB                  = 
MODELREF_LINK_LIBS        = $(subst \,/,)
RELATIVE_PATH_TO_ANCHOR   = $(subst \,/,..)
MODELREF_TARGET_TYPE      = NONE

ADDITIONAL_LDFLAGS   = 

SRCS		= UNICARPTMotor_capi.c

ifeq ($(MODELREF_TARGET_TYPE), NONE)
	# Top model for RTW
all:	ModelMainLib
else
	# sub-model for RTW or sharedutils library
all:	ModelRefLib
endif

OBJS	= $(patsubst rt_malloc_main.o,,$(SRCS:.c=.o))
ifeq ($(MODELREF_TARGET_TYPE), NONE)
  OBJS	+= $(MODEL).o $(WRAPPER).o
endif

LIBS		=

# linkLibsObjs from rtwmakecfg.m, rtwlib (must be excluded, collides with libmatsupp.a):

# physical model libraries (must be excluded, collide with libmatsupp.a):

# Custom code libraries, S-function modules specified with an absolute path:
LIBS		+= $(subst \,/,)


# Directory where the CarMaker executable is compiled.
CM_SRCDIR	= "$(subst \,/,..)"
CM_PROJHOOKUP	= 1
CM_PROJMAKE	= 1


# Top-level directory of the Matlab include files.
# Usually, this is identical to the Matlab root directory, but maybe
# you want to use a local copy of the Matlab includes files in e.g.
# ../../include/R2019b
CM_MATINCTMP	= 
ifeq ($(CM_MATINCTMP), )
CM_MATINCPATH	= $(MATLAB_ROOT)
else
CM_MATINCPATH	= "$(subst \,/,$(CM_MATINCTMP))"
endif


#OPT_CFLAGS	= -g
USR_CFLAGS	=  
DEF_CFLAGS	+= -DRT -DRT_MALLOC -DUSE_RTMODEL -DMODEL=$(MODEL) \
		   -DPARAMID=$(PARAMID) -DMATSUPP_NUMVER=$(MATSUPP_NUMVER) \
		   -DARCH="\"$(ARCH)\"" "-DBUILDDATE=\"`date '+%F'`\"" "-DBUILDTIME=\"`date '+%H:%M'`\""

# suppress warnings about physical model headers
ifneq	(,)
CFLAGS          += -Wno-unused  -Wno-missing-prototypes
endif

ifneq ($(MODELREFS), "")
  DEF_CFLAGS += -DMODELREFS
endif

INC_CFLAGS	+= -I. -I$(RELATIVE_PATH_TO_ANCHOR) \
		   -I$(CM_SRCDIR) -I$(MATSUPP_DIR) \
		   -I$(CM_MATINCPATH)/simulink/include \
		   -I$(CM_MATINCPATH)/extern/include \
		   -I$(CM_MATINCPATH)/rtw/c/src \
		   -I$(CM_MATINCPATH)/rtw/c/src/ext_mode/common \
		   -I$(CM_MATINCPATH)/rtw/c/libsrc

INC_CFLAGS	+= -I$(subst \,/,"C:\Users\Tobias\Documents\Git\cm-ap24\src_cm4sl")
INC_CFLAGS	+= -I$(subst \,/,"C:\Users\Tobias\Documents\Git\cm-ap24\src_cm4sl\UNICARPTMotor_CarMaker_rtw")
INC_CFLAGS	+= -I$(subst \,/,"$(MATLAB_ROOT)\extern\include")
INC_CFLAGS	+= -I$(subst \,/,"$(MATLAB_ROOT)\simulink\include")
INC_CFLAGS	+= -I$(subst \,/,"$(MATLAB_ROOT)\rtw\c\src")
INC_CFLAGS	+= -I$(subst \,/,"$(MATLAB_ROOT)\rtw\c\src\ext_mode\common")


V = 0
ifeq ($V,1)
  Q =
  QECHO = @true
else
  Q = @
  QECHO = @echo
endif


%.o:		%.c
	$(QECHO) " CC       $@"
	$Q $(CC) $(CFLAGS) -c $<
%.o:		$(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(QECHO) " CC       $@"
	$Q $(CC) $(CFLAGS) -c $<

# Rules for library modules in additional directories.
# Modules from somewhere below MATLAB_ROOT/rtw/c must be excluded
# to avoid collision with their precompiled version in libmatsupp.a.

ifeq ($(findstring $(MATLAB_ROOT)/rtw/c/,$(subst \,/,$(MATLAB_ROOT)\rtw\c\src)),)
%.o: $(subst \,/,$(MATLAB_ROOT)\rtw\c\src)/%.c
	$(QECHO) " CC       $@"
	$Q $(CC) $(CFLAGS) -c $<
endif

ifeq ($(findstring $(MATLAB_ROOT)/rtw/c/,$(subst \,/,$(MATLAB_ROOT)\simulink\src)),)
%.o: $(subst \,/,$(MATLAB_ROOT)\simulink\src)/%.c
	$(QECHO) " CC       $@"
	$Q $(CC) $(CFLAGS) -c $<
endif



ModelMainLib:	../lib$(MODEL)_$(ARCH).a
	$(QECHO) " MKENTRY  $(CLASS) $(MODEL) $(PARAMID)"
	$Q $(CMPU) mkentry -s $(CM_SRCDIR) -c $(CLASS) -m $(MODEL) -d $(DESCRIPTION) -i $(PARAMID)
ifeq ($(CM_PROJHOOKUP), 1)
	$(QECHO) " HOOKUP   $(MODEL)"
	$Q $(CMPU) hookup  -s $(CM_SRCDIR) -c $(CLASS) -m $(MODEL) -a $(ARCH) -mm $(MAINMODEL) -mv $(MATSUPP_MATVER) -mr $(MATLAB_ROOT)
endif
ifeq ($(CM_PROJMAKE), 1)
	@echo "Executing 'make' in the project source directory..."
 ifeq ($(ARCH), ds1006)
  ifneq ($(MAINMODEL), "")
	cd $(CM_SRCDIR)/$(MAINMODEL)_*1006 && $(DSMAKECMD) -f $(MAINMODEL).mk
  endif
 else
	$(MAKE) -C $(CM_SRCDIR) V=$V
 endif
endif
	@echo "### Created model library: lib$(MODEL)_$(ARCH).a"


../lib$(MODEL)_$(ARCH).a:	$(OBJS) $(MODELREF_LINK_LIBS) $(LIBS)
ifeq ($(filter linux64 win32 win64 xeno lvrt nilrt ds1006 dsrt, $(ARCH)), )
	$Q rm -f $@
	$(QECHO) " AR qs    $@"
	$Q $(AR) qs $@ $(OBJS)
else
	$(QECHO) " MKLIB    $@"
	$Q $(CMPU) mklib -a $(ARCH) -m $(MODEL) -k $(SYMBOLS) \
		-o $@ $(OBJS) $(MODELREF_LINK_LIBS) $(LIBS) \
		$(MATSUPP_LIB) $(ADDITIONAL_LDFLAGS)
endif

ModelRefLib:	$(OBJS) $(LIBS)
	$Q rm -f $(MODELLIB)
	$(QECHO) "AR qs $(MODELLIB)"
	$Q $(AR) qs $(MODELLIB) $(OBJS)
	@echo "### Created $(MODELLIB)"

clean:
	/bin/rm -f *.o *% a.out *~ *_rtwlib.a
ifeq ($(MODELREF_TARGET_TYPE), NONE)
	/bin/rm -f  $(RELATIVE_PATH_TO_ANCHOR)/lib$(MODEL)_$(ARCH).a
endif


# Additional dependencies
ifeq ($(MODELREF_TARGET_TYPE), NONE)
  $(WRAPPER).o:	$(WRAPPER).h $(MODEL).h
  $(MODEL).o:	$(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_private.h $(WRAPPER).h
else
  $(MODEL).o:	$(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_private.h
endif


rt_backsubcc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_backsubcc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_backsubrc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_backsubrc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_backsubrr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_backsubrr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_forwardsubcc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_forwardsubcc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_forwardsubcr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_forwardsubcr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_forwardsubrc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_forwardsubrc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_forwardsubrr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_forwardsubrr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_logging.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_logging_mmi.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_lu_cplx.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_lu_cplx_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_lu_real.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_lu_real_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matdivcc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matdivcc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matdivcr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matdivcr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matdivrc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matdivrc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matdivrr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matdivrr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultandinccc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultandinccc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultandinccr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultandinccr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultandincrc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultandincrc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultandincrr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultandincrr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultcc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultcc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultcr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultcr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultrc_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultrc_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultrr_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matmultrr_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matrixlib_dbl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matrixlib_sgl.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_matrx.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_nonfinite.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_printf.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@
rt_sim.o:		$(CARMAKER_DIR_MK)/Matlab/$(MATSUPP_MATVER)/libmatsupp-$(ARCH).a
	$(QECHO) " AR x     $@"
	$Q $(AR) x $(MATSUPP_DIR)/libmatsupp-$(ARCH).a $@


# Libraries


# Precompiled libraries

