//
//  YKNetworkingConfig.h
//  YKBaseNetworking
//
//  Created by w.q... on 2020/10/20.
//

// common define
#define kMessage (@"errDesc")
#define kError   (@"errCode")
#define kData    (@"data")

// 返回码定义
#define kAPIResultCodeSuccess   @"0"       // 返回成功
#define kAPIResultCodeException @"-9999"   // 系统异常

// 超时时间类型
#define kYKTimeOutTypeNormal    @(10.0)
#define kYKTimeOutTypeOneMinute @(60.0)
#define kYKTimeOutTypeUnlimited @(90.0)

#define cYKTimeOutTypeGet ([[NSArray alloc] initWithObjects:\
kYKTimeOutTypeNormal,\
kYKTimeOutTypeOneMinute,\
kYKTimeOutTypeUnlimited, nil])

#define kYKTimeOutTypeNumber(type) ([cYKTimeOutTypeGet objectAtIndex:type])
#define kYKTimeOutTypeEnum(double) ([cYKTimeOutTypeGet indexOfObject:double])

/// 安全字符串
#define kSafeString(string) ((![string isKindOfClass:[NSString class]]) || \
                             ([string isKindOfClass:[NSNull class]]) || \
                             (!string) || \
                             (0 == string.length)  \
                            ? @"" : string)

typedef NS_ENUM(NSInteger, YKParameterType) {
    YKParameterTypeDictionary = 0,
    YKParameterTypeArray,
};

typedef NS_ENUM(NSInteger, YKNetworkResult) {
    YKNetworkResultNetworkUnavailable = 1,
    YKNetworkResultFailed,
    YKNetworkResultSuccess,
};

typedef NS_ENUM(NSInteger, YKRequestSerializerType) {
    YKRequestSerializerTypeHTTP = 0,
    YKRequestSerializerTypeJSON,
};

typedef NS_ENUM(NSInteger, YKTimeOutType) {
    YKTimeOutTypeNormal = 0,
    YKTimeOutTypeOneMinute,
    YKTimeOutTypeUnlimited,
};

typedef NS_ENUM(NSInteger, YKRequestMethod) {
    YKRequestMethodGET,
    YKRequestMethodPOST,
    YKRequestMethodDELETE,
};
