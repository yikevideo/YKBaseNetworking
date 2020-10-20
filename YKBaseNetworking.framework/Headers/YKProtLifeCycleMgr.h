//
//  YKProtLifeCycleMgr.h
//  YKBaseNetworking
//
//  Created by w.q... on 2020/10/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// == Begin == 创建单例代码
#define DECLARE_SINGLETON_FOR_CLASS(classname, accessorname)    \
+ (classname *)accessorname;

#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname, accessorname) \
+ (classname *)accessorname                                     \
{                                                               \
static classname *accessorname = nil;                       \
static dispatch_once_t onceToken;                           \
dispatch_once(&onceToken, ^{                                \
accessorname = [[classname alloc] init];                \
});                                                         \
return accessorname;                                        \
}
// == End == 创建单例代码

@class YKNetworkingBase;
@interface YKProtLifeCycleMgr : NSObject
DECLARE_SINGLETON_FOR_CLASS(YKProtLifeCycleMgr, sharedMgr)

@property (nonatomic, strong) NSMutableSet *workingProtocols;
- (void)yk_attachProtocolReference:(YKNetworkingBase *)protocol;
- (void)yk_releaseProtocolReference:(YKNetworkingBase *_Nonnull*_Nullable)protocol;

@end

NS_ASSUME_NONNULL_END
