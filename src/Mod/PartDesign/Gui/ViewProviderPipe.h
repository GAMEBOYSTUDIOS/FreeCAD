/***************************************************************************
 *   Copyright (c) 2015 Stefan Tröger <stefantroeger@gmx.net>              *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef PARTGUI_ViewProviderPipe_H
#define PARTGUI_ViewProviderPipe_H

#include "ViewProviderAddSub.h"

namespace PartDesignGui {

class PartDesignGuiExport ViewProviderPipe : public ViewProviderAddSub
{
    PROPERTY_HEADER(PartDesignGui::ViewProviderPipe);

public:
    /// constructor
    ViewProviderPipe();
    /// destructor
    virtual ~ViewProviderPipe();

    /// grouping handling 
    std::vector<App::DocumentObject*> claimChildren(void)const;
    void setupContextMenu(QMenu*, QObject*, const char*);
    bool doubleClicked();

    virtual bool onDelete(const std::vector<std::string> &);
    void highlightReferences(const bool on, bool auxiliary);
    
protected:
    virtual QIcon getIcon(void) const;
    virtual bool setEdit(int ModNum);
    virtual void unsetEdit(int ModNum);
    
    /// Returns a newly created TaskDlgPipeParameters
    virtual TaskDlgFeatureParameters *getEditDialog();
    
private:
    std::vector<App::Color> originalLineColors;
};


} // namespace PartDesignGui


#endif // PARTGUI_ViewProviderPipe_H
