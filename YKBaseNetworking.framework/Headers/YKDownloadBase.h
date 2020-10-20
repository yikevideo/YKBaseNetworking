//
//  YKDownloadBase.h
//  YKBaseNetworking
//
//  Created by w.q... on 2020/10/20.
//

#import "YKNetworkingBase.h"

NS_ASSUME_NONNULL_BEGIN

@class YKNetworkingBase;
@protocol YKDownloadProtDelegate <NSObject>

@optional
- (void)yk_downloadProtCallBack:(YKNetworkingBase *)protocol
               downloadProgress:(NSProgress *)downloadProgress;

@end
@interface YKDownloadBase : YKNetworkingBase
@property (nonatomic, weak) id<YKDownloadProtDelegate> downloadDelegate;
@property (nonatomic, strong) NSProgress *downloadFileProgress;

- (void)      yk_startDownloadWithDelegate:(id)delegate;
- (NSString *)yk_requestDownLoadUrl;
- (NSString *)yk_fileAbsolutePath;
- (void)      yk_onDownloadFinish:(NSURLResponse *)response
                         filePath:(NSURL *)filePath
                            error:(NSError *)error;
- (BOOL)      yk_handleDownloadFinishBySelf;
@end

NS_ASSUME_NONNULL_END
