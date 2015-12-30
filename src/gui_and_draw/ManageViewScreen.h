//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//
//////////////////////////////////////////////////////////////////////

#ifndef _VSP_GUI_VIEW_MANAGER_SCREEN_H
#define _VSP_GUI_VIEW_MANAGER_SCREEN_H

#include "ScreenBase.h"
#include "Parm.h"
#include <math.h>

using namespace std;

//class ScreenMgr;
class ManageViewScreen : public BasicScreen
{
public:
    ManageViewScreen( ScreenMgr * mgr );
    virtual ~ManageViewScreen();

    void Show();
    void Hide();
    bool Update();

    virtual void GuiDeviceCallBack( GuiDevice* device );

    virtual void CallBack( Fl_Widget* w );
    virtual void CloseCallBack( Fl_Widget *w );
    static void staticScreenCB( Fl_Widget *w, void* data )
    {
        ( ( ManageViewScreen* )data )->CallBack( w );
    }

    void LoadDrawObjs(vector< DrawObj* > & draw_obj_vec);

    /*!
     * Updates Viewport GUI devices for changes that occur manually
     * in the application; i.e: User manually resizes the window.
     */
    void UpdateViewport();

    /*!
     * Updates Center of Rotation GUI devices for changes that occur
     * manually in the application; i.e: User presses 'r' key for
     * manually selection.
     */
    void UpdateCOR();

    /*!
     * Updates Pan GUI device values for when user manually pans using
     * the cursor.
     */
    void UpdatePan();

    /*!
     * Updates Zoom GUI device value for when user manually zooms using
     * cursor or key presses.
     */
    void UpdateZoom();

    /*!
     * Updates Euler Rotation GUI device values when user manually rotates
     * the scene with the cursor.
     */
    void UpdateRotations();

    /*!
     * Updates entire GUI device with updated values from the display.
     */
    void UpdateAll();

protected:

    GroupLayout m_MainLayout;
    GroupLayout m_BorderLayout;

    SliderAdjRangeInput m_ViewportSizeX;
    SliderAdjRangeInput m_ViewportSizeY;

    TriggerButton m_SetDefaultViewportSize;

    SliderAdjRangeInput m_CORX;
    SliderAdjRangeInput m_CORY;
    SliderAdjRangeInput m_CORZ;

    TriggerButton m_PickLookAtBtn;
    TriggerButton m_ResetOriginLookAtBtn;

    SliderAdjRangeInput m_PanXPos;
    SliderAdjRangeInput m_PanYPos;
    LogSliderAdjRangeInput m_Zoom;

    //===== Attempt at Euler Angle Rotation =====//
    SliderAdjRangeInput m_XRotation;
    SliderAdjRangeInput m_YRotation;
    SliderAdjRangeInput m_ZRotation;

    TriggerButton m_ResetCamera;

    int windowDX;
    int windowDY;

    IntParm m_ViewportSizeXValue;
    IntParm m_ViewportSizeYValue;

    //===== Center of Rotation Values =====//

    FractionParm m_CORXValue;
    FractionParm m_CORYValue;
    FractionParm m_CORZValue;

    FractionParm m_PanXPosValue;
    FractionParm m_PanYPosValue;

    FractionParm m_ZoomValue;

    //===== Attempt at Euler Angle Rotation =====//

    FractionParm m_XRotationValue;
    FractionParm m_YRotationValue;
    FractionParm m_ZRotationValue;

};

#endif