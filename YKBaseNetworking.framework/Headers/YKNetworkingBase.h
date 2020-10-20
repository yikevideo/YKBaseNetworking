//
//  YKNetworkingBase.h
//  YKBaseNetworking
//
//  Created by w.q... on 2020/10/20.
//

#import <Foundation/Foundation.h>
#import "YKNetworkingConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class YKNetworkingBase, AFHTTPSessionManager;
@protocol YKNetworkingProtDelegate <NSObject>

@required
- (void)yk_networkProtCallBack:(YKNetworkingBase *)prot;

@end
@interface YKNetworkingBase : NSObject
@property (nonatomic, weak) id <YKNetworkingProtDelegate> delegate;
@property (nonatomic)           YKNetworkResult workResult;
@property (nonatomic, copy)           NSString *optCode;
@property (nonatomic, copy, nullable) NSString *optDesc;
@property (nonatomic, strong)                id responseObject;
@property (nonatomic, strong, nullable)      id optData;
@property (nonatomic, assign)   YKRequestMethod requestMethod;

+ (AFHTTPSessionManager *)yk_sharedHttpRequestManager;
+ (AFHTTPSessionManager *)yk_sharedHttpRequestHttpResponseManager;
+ (void)yk_serverURLDidChange;
- (void)yk_startWork;
- (void)yk_startWorkWithDelegate:(id)delegate;
- (void)yk_notifyDelegate;
- (void)yk_handleRequestSerializer;

/// 请求路径  ⚠️子类必须实现此方法
- (NSString *)yk_requestApiPath;

/// 配置请求参数  ⚠️子类必须实现此方法
- (NSMutableDictionary *)yk_requestParams;

/// 配置请求参数
- (NSArray *)yk_requestParamsArray;

///  响应数据 子类必须实现此方法⚠️
///  如果 - (BOOL)yk_handleResponseBySelf; 子类重写返回YES时 响应数据为原始数据
/// @param responseObject 响应数据
- (void)yk_onResponse:(id)responseObject;

/// 子类自定制请求参数配置
- (NSMutableDictionary *)yk_packageApiRequestingParams;

/// 子类可以决定是否自行处理响应的原始数据 默认为No 由基类统一处理
- (BOOL)yk_handleResponseBySelf;

/// 子类自定制公共参数
- (NSMutableDictionary *)yk_handleCommonParams;

/// 请求URL 子类可以自定制URL
- (NSString *)yk_handleURLString;

/// 请求BaseURL 子类可以自定制URL
- (NSString *)yk_requestApiBaseUrl;

/// 子类可以自定制响应message的key值 默认的key为 errDesc
/// @param responseObj 响应数据
- (NSString *)yk_getOptDesc:(id)responseObj;

/// 子类可以自定制响应code的key值 默认的key为 errCode
/// @param responseObj 响应数据
- (NSString *)yk_getOptCode:(id)responseObj;

/// 子类可以自定制响应code的key值 默认的key为 errCode
/// @param responseObj 响应数据
- (id)yk_getOptData:(id)responseObj;

/// 子类可以自定制base url 有默认值
- (NSString *)yk_generateBaseURL;

/// 子类可以自定制请求参数类型
- (YKParameterType)yk_handleParameterType;

/// 子类可以配置post请求序列化方式 默认为json
- (YKRequestSerializerType)yk_handleRequestSerializerType;

/// 子类可以配置超时时间类型 默认为60秒
- (YKTimeOutType)yk_handleTimeOutType;
@end

NS_ASSUME_NONNULL_END
