//def evaluate_candidate(candidate, blind_attrs, threat_attrs):
//    """评估一个候选攻击属性：覆盖盲点数量（允许1倍）、克制威胁数量（必须>1倍）"""
//    # 修改点：将 > 1.0 改为 >= 1.0，使1倍伤害也能覆盖盲点
//    cover_blind = [b for b in blind_attrs if get_multiplier(candidate, b) >= 1.0]
//    # 克制威胁仍要求 > 1.0（2倍克制效果更好）
//    cover_threat = [t for t in threat_attrs if get_multiplier(candidate, t) > 1.0]
//    return len(cover_blind), len(cover_threat), cover_blind, cover_threat
//
//def recommend(own_types, existing_attacks):
//    """主推荐函数"""
//    blind = get_blind_attributes(existing_attacks)
//    threats = get_threat_attributes(own_types)
//    
//    print(f"盲点属性: {blind}")
//    print(f"威胁属性: {threats}")
//    
//    candidates = []
//    for cand in ATTRIBUTES:
//        cb, ct, cb_list, ct_list = evaluate_candidate(cand, blind, threats)
//        candidates.append((cand, cb, ct, cb_list, ct_list))
//    
//    # 排序：先按盲点覆盖数降序，再按威胁克制数降序
//    candidates.sort(key=lambda x: (x[1], x[2]), reverse=True)
//    
//    print("\n候选技能属性推荐（按盲点覆盖数降序，再按威胁克制数降序）：")
//    for cand, cb, ct, cb_list, ct_list in candidates:
//        if cb == 0 and ct == 0:
//            continue  # 跳过完全无用的属性
//        print(f"属性: {cand} -> 覆盖盲点: {cb}个 ({', '.join(cb_list)}), 克制威胁: {ct}个 ({', '.join(ct_list)})")
#pragma once

namespace pokemon{



}//namespace pokemon
