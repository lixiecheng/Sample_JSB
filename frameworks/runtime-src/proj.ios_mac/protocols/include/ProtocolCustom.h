/** @file ProtocolCustom.h
 */
#ifndef  __CCX_PROTOCOL_CUSTOM_H__
#define  __CCX_PROTOCOL_CUSTOM_H__

#include "PluginProtocol.h"
#include <map>
#include <string>
#include <functional>

namespace anysdk { namespace framework {
typedef enum 
{
    kCustomExtension = 80000 /**< enum value is  extension code . */
} CustomResultCode;
/**   
 *@class  CustomResultListener
 *@brief the interface of share callback  
 */
class CustomResultListener
{
public:
	/**   
	 *@brief the interface of share callback 
	 *@param the id of callback
	 *@param the information of callback
	 */
    virtual void onCustomResult(CustomResultCode ret, const char* msg) = 0;
};
/**   
 *@class  ProtocolCustom
 *@brief the interface of custom  
 */
class ProtocolCustom : public PluginProtocol
{
public:

    /**
    @breif set the result listener
    @param pListener The callback object for custom result
    @wraning Must invoke this interface before custom
    */
    virtual void setResultListener(CustomResultListener* pListener) = 0;

    virtual CustomResultListener* getCustomListener() = 0;

#ifndef AS_NO_USING_CPP11
	typedef std::function<void(int, std::string&)> ProtocolCustomCallback;

    /**
     @brief set custom callback function
     */
    virtual void setCallback(const ProtocolCustomCallback &cb) = 0;

    /**
     @brief get custom callback function
     */
    virtual ProtocolCustomCallback& getCallback() = 0;
#endif
};

}} // namespace anysdk { namespace framework {

#endif   /* ----- #ifndef __CCX_PROTOCOL_Custom_H__ ----- */
