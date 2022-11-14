/*
    *
    * This file is a part of CoreAction.
    * A side bar for showing widgets for C Suite.
    * Copyright 2019 CuboCore Group
    *

    *
    * This program is free software; you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation; either version 3 of the License, or
    * (at your option) any later version.
    *

    *
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    * GNU General Public License for more details.
    *

    *
    * You should have received a copy of the GNU General Public License
    * along with this program; if not, vsit http://www.gnu.org/licenses/.
    *
*/


#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QNetworkReply>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDir>

#include "apirequest.h"

apiRequest::apiRequest(QObject *parent)
	: QObject(parent)
{
	nam = new QNetworkAccessManager(this);
	m_reties = 5;
}

apiRequest::~apiRequest()
{
	delete nam;
}

bool apiRequest::requestData(QString url, QString filepath, Reason r)
{
	auto request = QNetworkRequest(QUrl(url));
	request.setHeader(QNetworkRequest::UserAgentHeader, QString("Mozilla/5.0 (X11; Linux x86_64; rv:99.0) Gecko/20100101 Firefox/99.0"));

	auto reply = nam->get(request);

	connect(reply, &QNetworkReply::finished, [this, url, filepath, r, reply]() {
		QByteArray data = reply->readAll();

		if (data.isEmpty()) {
			if (m_reties) {
				qWarning() << "Retrying...";
				m_reties--;
				requestData(url, filepath, r);
			} else {
				m_reties = 5;
				QMessageBox::warning(nullptr, "Network Error", "Cannot download network data.\nMaybe network error.");
			}
		} else {
			QFile file(filepath);
			if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
				QTextStream in(&file);
				in << data;
				file.close();
				emit fileDownloaded(r);
			} else {
				qWarning() << "Can not save requested weather data at '" << QString(filepath).replace(QRegularExpression("^(" + QDir::homePath() + ")"), "~") << "'";
			}
		}
	});

	return true;
}
