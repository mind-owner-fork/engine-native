#pragma once

#import <Metal/MTLRenderPass.h>
#import <Metal/MTLPixelFormat.h>
#import <Metal/MTLTexture.h>

NS_CC_BEGIN

class GFXTextureView;

class CCMTLRenderPass : public GFXRenderPass
{
public:
    CCMTLRenderPass(GFXDevice* device);
    ~CCMTLRenderPass();
    
    virtual bool initialize(const GFXRenderPassInfo& info) override;
    virtual void destroy() override;
    
    void setColorAttachment(id<MTLTexture> texture);
    void setDepthStencilAttachment(id<MTLTexture> texture);
    
    CC_INLINE MTLRenderPassDescriptor* getMTLRenderPassDescriptor() const { return _mtlRenderPassDescriptor; }
    
private:
    MTLRenderPassDescriptor* _mtlRenderPassDescriptor = nil;
};

NS_CC_END