import React from "react";
import Layout from "../components/layout";

import "./contact.css";

const ContactPage = () => (
    <Layout className="contact">
        <section>
            <ul>
                <li>
                    email:{" "}
                    <a href="mailto:matt.e.greer@gmail.com">
                        matt.e.greer@gmail.com
                    </a>
                </li>
                <li>
                    twitter:{" "}
                    <a href="https://twitter.com/mattegreer">mattegreer</a>
                </li>
                <li>
                    blog: <a href="http://mattgreer.org">mattgreer.org</a>
                </li>
            </ul>
        </section>
    </Layout>
);

export default ContactPage;
