FROM gcc:latest

USER root

WORKDIR /app

#RUN apt-get update && apt-get install -y \ make \ libcurl4-openssl-dev \libsctp-dev \ iproute2 \ net-tools \ pkg-config \
 #   && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y \
    make \
    libcurl4-openssl-dev \
    libsctp-dev \
    iproute2 \
    net-tools \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*
COPY . /app

WORKDIR /app/RIC/emulator

#CMD ["sh", "-c", "./make.sh 1 && ./run.sh"]
CMD ["sh", "-c", "sed -i \"s/10.1.103.57/${SERVER_IP}/g\" /app/RIC/emulator/e2smrc/Ric_hdl.c && ./make.sh 1 && ./run.sh"]




