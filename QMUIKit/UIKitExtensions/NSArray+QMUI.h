/**
 * Tencent is pleased to support the open source community by making QMUI_iOS available.
 * Copyright (C) 2016-2021 THL A29 Limited, a Tencent company. All rights reserved.
 * Licensed under the MIT License (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
 * http://opensource.org/licenses/MIT
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
 */

//
//  NSArray+QMUI.h
//  QMUIKit
//
//  Created by QMUI Team on 2017/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray<ObjectType> (QMUI)

/**
 将多个对象合并成一个数组，如果参数类型是数组则会将数组内的元素拆解出来加到 return 内（只会拆解一层，所以多维数组不处理）

 @param object 要合并的多个数组
 @return 合并完的结果
 */
+ (instancetype)qmui_arrayWithObjects:(ObjectType)object, ...;

/**
 *  将多维数组打平成一维数组再遍历所有子元素
 */
- (void)qmui_enumerateNestedArrayWithBlock:(void (NS_NOESCAPE^)(id obj, BOOL *stop))block;

/**
 *  将多维数组递归转换成 mutable 多维数组
 */
- (NSMutableArray *)qmui_mutableCopyNestedArray;

/**
 *  过滤数组元素，将 block 返回 YES 的 item 重新组装成一个数组返回
 */
- (NSArray<ObjectType> *)qmui_filterWithBlock:(BOOL (NS_NOESCAPE^)(ObjectType item))block;

/**
 过滤数组元素，将第一个令 block 返回值为 YES 的元素返回，如果不存在则返回 nil
 */
- (ObjectType _Nullable)qmui_firstMatchWithBlock:(BOOL (NS_NOESCAPE^)(ObjectType item))block;

/**
*  转换数组元素，将每个 item 都经过 block 转换成一遍后返回一个等长的数组。
*/
- (NSArray *)qmui_mapWithBlock:(id (NS_NOESCAPE^)(ObjectType item, NSInteger index))block;

/**
*  转换数组元素，将每个 item 经过 block 转换为另一个元素，如果希望移除该 item，可返回 nil。当所有元素都被移除时，本方法返回空的容器。
*/
- (NSArray *)qmui_compactMapWithBlock:(id _Nullable (NS_NOESCAPE^)(ObjectType item))block;

@end

NS_ASSUME_NONNULL_END
