#pragma once

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define M_MODE  mUserMode
  #define M_MODE_ mUserMode,
#else
  #define M_MODE
  #define M_MODE_
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define MODE  inArgumentForCheckingRoutineCalls
  #define MODE_ inArgumentForCheckingRoutineCalls,
#else
  #define MODE
  #define MODE_
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   B O O T    M O D E
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  class BOOT_mode_class {
    private : BOOT_mode_class (void) ;
    private : BOOT_mode_class & operator = (const BOOT_mode_class &) ;

    public : BOOT_mode_class (const BOOT_mode_class &) ;
  } ;
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define BOOT_MODE const BOOT_mode_class MODE
  #define UNUSED_BOOT_MODE const BOOT_mode_class
#else
  #define BOOT_MODE void
  #define UNUSED_BOOT_MODE void
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   I N I T    M O D E
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  class INIT_mode_class {
    private : INIT_mode_class (void) ;
    private : INIT_mode_class & operator = (const INIT_mode_class &) ;

    public : INIT_mode_class (const INIT_mode_class &) ;
  } ;
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define INIT_MODE  const INIT_mode_class MODE
  #define INIT_MODE_ const INIT_mode_class MODE,
#else
  #define INIT_MODE  void
  #define INIT_MODE_
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   U S E R    M O D E
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  class USER_mode_class {
    private : USER_mode_class (void) ;
    private : USER_mode_class & operator = (const USER_mode_class &) ;

    public : USER_mode_class (const USER_mode_class &) ;
  } ;
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define USER_MODE   const USER_mode_class MODE
  #define USER_MODE_  const USER_mode_class MODE,
#else
  #define USER_MODE  void
  #define USER_MODE_
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   K E R N E L    M O D E
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  class KERNEL_mode_class {
    private : KERNEL_mode_class (void) ;
    private : KERNEL_mode_class & operator = (const KERNEL_mode_class &) ;

    public : KERNEL_mode_class (const KERNEL_mode_class &) ;
  } ;
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define KERNEL_MODE   const KERNEL_mode_class MODE
  #define KERNEL_MODE_  const KERNEL_mode_class MODE,
#else
  #define KERNEL_MODE   void
  #define KERNEL_MODE_
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//  I R Q    M O D E
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  class IRQ_mode_class {
    private : IRQ_mode_class (void) ;
    private : IRQ_mode_class & operator = (const IRQ_mode_class &) ;

    public : IRQ_mode_class (const IRQ_mode_class &) ;
    public : IRQ_mode_class (const KERNEL_mode_class &) ;
    public : IRQ_mode_class (const INIT_mode_class &) ;
  } ;
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define IRQ_MODE   const IRQ_mode_class MODE
  #define IRQ_MODE_  const IRQ_mode_class MODE,
#else
  #define IRQ_MODE   void
  #define IRQ_MODE_
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   S E C T I O N    M O D E
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  class SECTION_mode_class {
    private : SECTION_mode_class (void) ;
    private : SECTION_mode_class & operator = (const SECTION_mode_class &) ;

    public : SECTION_mode_class (const SECTION_mode_class &) ;
    public : SECTION_mode_class (const IRQ_mode_class &) ;
    public : SECTION_mode_class (const KERNEL_mode_class &) ;
    public : SECTION_mode_class (const INIT_mode_class &) ;
  } ;
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define SECTION_MODE  const SECTION_mode_class MODE
  #define SECTION_MODE_ const SECTION_mode_class MODE,
#else
  #define SECTION_MODE  void
  #define SECTION_MODE_
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   F A U L T    M O D E
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  class FAULT_mode_class {
    private : FAULT_mode_class (void) ;
    private : FAULT_mode_class & operator = (const FAULT_mode_class &) ;

    public : FAULT_mode_class (const FAULT_mode_class &) ;
  } ;
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef CHECK_ROUTINE_CALLS
  #define FAULT_MODE  const FAULT_mode_class MODE
  #define FAULT_MODE_ const FAULT_mode_class MODE,
#else
  #define FAULT_MODE  void
  #define FAULT_MODE_
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————