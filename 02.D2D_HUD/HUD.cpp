#include "HUD.h"
#include "UIRect.h"
#include "D2DResource.h"
#include <wrl/client.h>
#include <boost/property_tree/xml_parser.hpp>
#include <d2d1_1.h>


HUD::HUD()
{}

bool HUD::Load(const std::string &path)
{
    boost::property_tree::wptree pt;
	//boost::property_tree::read_json(path.c_str(), pt);
	boost::property_tree::read_xml(path.c_str(), pt);
	if (pt.empty()){
        return false;
    }

	// build tree
	if (auto layout = pt.get_child_optional(L"UI.Rect")){
		m_root = std::make_shared<UIRect>();

		// root node default attrubutes
		auto textformat = std::make_shared<D2DTextFormat>(L"Verdana", 50.0f);
		m_root->SetTextFormat(textformat);

		auto fg=std::make_shared<D2DSolidColorBrush>(D2D1::ColorF::Black);
		m_root->SetFG(fg);

		// traverse ui tree
		m_root->Traverse(*layout);
	}

    return true;
}

void HUD::Update(const std::chrono::milliseconds &elapsed)
{
	if (!m_root)return;
}

void HUD::Render(ID2D1DeviceContext *pRenderTarget)
{
	if (!m_root)return;

    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
    D2D1_SIZE_F rtSize = pRenderTarget->GetSize();
	m_root->Layout(UIRect::Rect(0, 0, rtSize.width, rtSize.height));
    m_root->Render(pRenderTarget);
}
