/*---------------------------------------------------------------------------*
  Project:  NitroSDK - MI - include
  File:     allocator.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

 *---------------------------------------------------------------------------*/
#ifndef	NITRO_MI_ALLOCATOR_H_
#define	NITRO_MI_ALLOCATOR_H_


#include <nitro/misc.h>
#include <nitro/types.h>
#include <nitro/platform.h>


#ifdef __cplusplus
extern  "C"
{
#endif


/*---------------------------------------------------------------------------*/
/* declarations */

/* �������A���P�[�^�֐��v���g�^�C�v */
typedef void* (*MIAllocatorAllocFunction)(void *userdata, u32 length, u32 alignment);
typedef void  (*MIAllocatorFreeFunction)(void *userdata, void *buffer);

/* �������A���P�[�^�\���� */
typedef struct MIAllocator
{
    void                       *userdata;
    MIAllocatorAllocFunction    Alloc;
    MIAllocatorFreeFunction     Free;
}
MIAllocator;


/*---------------------------------------------------------------------------*/
/* functions */

/*---------------------------------------------------------------------------*
  Name:         MI_InitAllocator

  Description:  �A���P�[�^��������.

  Arguments:    allocator        ����������MIAllocator�\����.
                userdata         �C�ӂ̃��[�U��`����.
                alloc            �������m�ۊ֐��̃|�C���^.
                free             ����������֐��̃|�C���^.

  Returns:      None.
 *---------------------------------------------------------------------------*/
PLATFORM_ATTRIBUTE_INLINE
void MI_InitAllocator(MIAllocator *allocator, void *userdata,
                      MIAllocatorAllocFunction alloc,
                      MIAllocatorFreeFunction free)
{
    allocator->userdata = userdata;
    allocator->Alloc = alloc;
    allocator->Free = free;
}

/*---------------------------------------------------------------------------*
  Name:         MI_CallAlloc

  Description:  �A���P�[�^���烁�����m��.

  Arguments:    allocator        ���������ꂽMIAllocator�\����.
                length           �m�ۂ���T�C�Y.
                alignment        �K�v�ȋ��E���� (2�ׂ̂���ł���K�v������)

  Returns:      �m�ۂ��ꂽ�������܂���NULL.
 *---------------------------------------------------------------------------*/
PLATFORM_ATTRIBUTE_INLINE
void* MI_CallAlloc(MIAllocator *allocator, u32 length, u32 alignment)
{
    return allocator->Alloc(allocator->userdata, length, alignment);
}

/*---------------------------------------------------------------------------*
  Name:         MI_CallFree

  Description:  �A���P�[�^�փ��������.

  Arguments:    allocator        ���������ꂽMIAllocator�\����.
                buffer           ������郁����.

  Returns:      None.
 *---------------------------------------------------------------------------*/
PLATFORM_ATTRIBUTE_INLINE
void MI_CallFree(MIAllocator *allocator, void *buffer)
{
    allocator->Free(allocator->userdata, buffer);
}


/*---------------------------------------------------------------------------*/


#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* NITRO_MI_ALLOCATOR_H_ */
/*---------------------------------------------------------------------------*
  $Log: allocator.h,v $
  Revision 1.1  2007/04/11 08:04:55  yosizaki
  initial upload.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/