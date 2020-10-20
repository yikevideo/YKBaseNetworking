//
//  YKUploadBase.h
//  YKBaseNetworking
//
//  Created by w.q... on 2020/10/20.
//

#import "YKNetworkingBase.h"

NS_ASSUME_NONNULL_BEGIN

@protocol YKUploadProtDelegate <NSObject>

@optional
- (void)yk_uploadProtCallBack:(YKNetworkingBase *)protocol
                uploadPrgress:(NSProgress *)uploadProgress;

@end
@interface YKUploadBase : YKNetworkingBase

@property (nonatomic, weak) id <YKUploadProtDelegate> uploadDelegate;
@property (nonatomic, strong) NSProgress *uploadFileProgress;

- (void)      yk_startUploadWithDelegate:(id)delegate;
- (NSString *)yk_requestUploadUrl;
- (NSString *)yk_fileAbsolutePath;
- (void)      yk_onUploadFinish:(NSURLResponse *)response error:(NSError *)error;
- (BOOL)      yk_handleUploadFinishBySelf;

@end

NS_ASSUME_NONNULL_END
