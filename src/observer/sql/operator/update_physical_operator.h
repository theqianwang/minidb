#pragma once

#include "sql/operator/physical_operator.h"
#include "sql/parser/parse.h"
#include <vector>

class Trx;
class UpdateStmt;

/**
 * @brief 物理算子，更新
 * @ingroup PhysicalOperator
 */
class UpdatePhysicalOperator : public PhysicalOperator
{
public:
    UpdatePhysicalOperator(Table *table,Field field,Value value);
    virtual ~UpdatePhysicalOperator() = default;

    PhysicalOperatorType type() const override { return PhysicalOperatorType::UPDATE; }
    RC open(Trx *trx) override;
    RC next() override;
    RC close() override;

    Tuple *current_tuple() override { return nullptr; }
private:
    Table *table_ = nullptr;
    Field field_;
    Value value_;

    Trx   *trx_   = nullptr;

};