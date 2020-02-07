﻿#pragma once

#include <QDialog>
#include <QtCore>
#include "common/QJsonModel.hpp"
#include "base/Qv2rayBase.hpp"
#include "ui_w_JsonEditor.h"


class JsonEditor : public QDialog, private Ui::JsonEditor
{
        Q_OBJECT

    public:
        explicit JsonEditor(QJsonObject rootObject, QWidget *parent = nullptr);
        ~JsonEditor();
        QJsonObject OpenEditor();

    private slots:
        void on_jsonEditor_textChanged();

        void on_formatJsonBtn_clicked();

    private:
        QJsonModel model;
        QJsonObject original;
        QJsonObject final;
};
